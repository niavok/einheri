/*
 * Sequance.h
 *
 *  Created on: 6 sept. 2010
 *      Author: tom
 */

#ifndef EIN_UTILS_SEQUANCE_H_
#define EIN_UTILS_SEQUANCE_H_
#include <iostream>
#include <typeinfo>

// SEQ Inspired by Loki lib
namespace einUtils {

class NullType{};
template < 	class T01=NullType,class T02=NullType,class T03=NullType,class T04=NullType,class T05=NullType,
        	class T06=NullType,class T07=NullType,class T08=NullType,class T09=NullType,class T10=NullType,
        	class T11=NullType,class T12=NullType,class T13=NullType,class T14=NullType,class T15=NullType,
        	class T16=NullType,class T17=NullType,class T18=NullType,class T19=NullType,class T20=NullType>
struct Seq
{
	typedef  Seq<T01, T02, T03, T04, T05, T06, T07, T08, T09, T10,
			 	 T11, T12, T13, T14, T15, T16, T17, T18, T19, T20> Type;
	typedef T01 Head;
	typedef typename Seq<     T02, T03, T04, T05, T06, T07, T08, T09, T10,
			 	 	 	 T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>::Type Tail;
};
template<>
struct Seq<>
{
	typedef NullType Type;
};

template <class TSeq, class TAction>
void apply(TSeq, TAction& action)
{
	typedef typename TSeq::Head Head;
	typedef typename TSeq::Tail Tail;
	action.operator()( new Head() );
	std::cout << typeid(Head).name() << std::endl;
	apply(typename TSeq::Tail(), action);
}
template <class TAction>
void apply(einUtils::Seq<>, TAction&){}
template <class T>
void apply(NullType, T&){}

}  // namespace einUtils

#endif /* EIN_UTILS_SEQUANCE_H_ */
