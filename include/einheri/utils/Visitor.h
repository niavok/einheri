/*
 * Visitor.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef VISITOR_H_
#define VISITOR_H_

#include <vector>
#include "Sequance.h"

namespace einUtils {

/////////////////
// TAG storage and creation
template<typename Base>
struct TagCounter {
	static size_t s_counter; // declaration
};
template<typename Base>
size_t TagCounter<Base>::s_counter; // definition: default 0

template<typename Visitable, typename Base>
struct TagHolder {
	static size_t s_tag;
};

template<typename Visitable, typename Base>
size_t GetTag() {
	size_t& tag = TagHolder<const Visitable, const Base>::s_tag;
	if (tag == 0) {
		// first time : generate tag
		tag = ++TagCounter<const Base>::s_counter;
	}
	return tag;
}
template<typename Visitable, typename Base>
size_t TagHolder<Visitable, Base>::s_tag = GetTag<Visitable, Base> ();

// tag retrieval
// Base class must inherit from Visitor
// TODO boost static assert on base ??
template<typename Base>
struct VisitableBase {
	template<typename Visitable>
	size_t GetTagHelper(const Visitable*) const {
		return GetTag<Visitable, Base> ();
	}
};
#define EIN_DEFINE_VISITABLE()        	\
  virtual size_t Tag() const          	\
  {                                   	\
    return this->GetTagHelper(this);  	\
  }

/////////////
// The VTable

template<typename Base, typename Func>
class VTable {
	std::vector<Func> table_; // storage
public:
	template<typename Visitable>
	void add(Func f) {
		size_t index = GetTag<Visitable, Base> (); // find the slot
		if (index >= table_.size()) {
			// find function for Base if it exists
			const size_t base_tag = GetTag<Base, Base> ();
			Func default_function = (base_tag >= table_.size()) ? 0 : table_[base_tag];
			// expand the table
			table_.resize(index + 1, default_function);
		}
		table_[index] = f;
	}

	Func operator[](size_t index) const {
		if (index >= table_.size()) {
			index = GetTag<Base, Base> ();
		}
		return table_[index];
	}

}; // VTable

/////////////////
// thunk
template<typename Visitable, typename Base>
struct GetVisitMethodArgumentType {
	typedef Visitable Type; // ReturnType Visit( Visitable& )
};
// specialize for const Base
template<typename Visitable, typename Base>
struct GetVisitMethodArgumentType<Visitable, const Base> {
	typedef const Visitable Type; // ReturnType Visit( const Visitable& )
};

template<typename Visitor, typename VisitedList, typename Invoker>
struct CreateVtable {
	typename Visitor::VTableType vtable_; /* vtable object */

	template<typename Visitable>
	void operator ()(const Visitable* /* hint */) {
		vtable_.template add<Visitable> (&Visitor::template thunk<Visitor, Visitable, Invoker>);
	}

	CreateVtable() {
		// add Base's visit function first
		(*this)(static_cast<typename Visitor::Base*> (0));

		// add visit function for each type in VisitedList
		apply(VisitedList(), *this);
	}
}; // CreateVtable

template<typename Visitor, typename VisitedList, typename Invoker>
struct GetStaticVtable {
	// declare static instanceof vtable
	static CreateVtable<Visitor, VisitedList, Invoker> s_table;

	// provide conversion operator
	operator const typename Visitor::VTableType*() const {
		return &s_table.vtable_;
	}
};

template<typename Base, typename TReturn = void>
class Visitor {
public:
	typedef Visitor<Base, TReturn> Type;
	typedef TReturn ReturnType;
	typedef ReturnType (Visitor::*Func)(Base&);
	typedef VTable<const Base, Func> VTableType;

public:
	Visitor() {
	}

	template<typename VisitedList, typename Invoker>
	void Visit(const VisitedList&, const Invoker&) {
		vtable_ = einUtils::GetStaticVtable<Type, VisitedList, Invoker> ();
	}

	template<typename VisitorImpl, typename Visitable, typename Invoker>
	ReturnType thunk(Base& b) {
		// manage the constness boost trait could do it ??
		typedef typename GetVisitMethodArgumentType<Visitable, Base>::Type VisitableType;
		VisitorImpl& visitor = static_cast<VisitorImpl&> (*this);
		VisitableType& visitable = static_cast<VisitableType&> (b);
		return Invoker::Invoke(visitor, visitable);
	}

	ReturnType operator()(Base& b) {
		Func thunk = (*vtable_)[b.Tag()]; // fetch thunk
		return (this->*thunk)(b); // pointer to member function syntax
	}

private:
	const VTableType* vtable_; // vtable pointer

}; // Visitor

// TODO (boost static_assert)
// check_member_function<ReturnType, VisitorImpl, Visitable> (&Visitor::name); // compile time assertion
#define EIN_VISIT_INVOKER( name )												\
struct {																		\
	template<typename VisitorImpl, typename Visitable>							\
	static ReturnType Invoke(VisitorImpl& visitor, Visitable& visitable) {		\
		return visitor.name(visitable);											\
	}																			\
}

} // namespace einUtils


////////////////////////////////:::
/////////////////////////////////
// Usage :
//class Cloner;
//struct Shape: public VisitableBase< Cloner >
//{
//	  EIN_DEFINE_VISITABLE()
//};
//struct Circle : public Shape
//{
//	  EIN_DEFINE_VISITABLE()
//};
//struct Square : public Shape
//{
//	  EIN_DEFINE_VISITABLE()
//};
//struct Rect : public Shape
//{
//	  EIN_DEFINE_VISITABLE()
//};
//
//class Cloner: public Visitor<const Shape, Shape*> {
//public:
//
//	Cloner(){
//      this->Visit(Seq<Circle, Square, Rect>::Type(), CloneInvoker())
//	}
//
//private:
//
//	template<typename SomeShape>
//	SomeShape * clone(const SomeShape& s) {
//		return new SomeShape(s);
//	}
//
//	typedef EIN_VISIT_INVOKER( clone ) CloneInvoker;
//
//};
//
//inline void func( const Shape& s )
//{
//	Cloner clone;
//	Shape* copy = clone( s ); // invoke () operator
//	// do some stuff
//}


#endif /* VISITOR_H_ */
