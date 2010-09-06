/*
 * MovableVisiter.h
 *
 *  Created on: 6 sept. 2010
 *      Author: tom
 */

#ifndef EIN_MOVABLEVISITER_H_
#define EIN_MOVABLEVISITER_H_

#include <einheri/utils/Visitor.h>

namespace ein {

class MovableVisiter: public einUtils::Visitor<MovableVisiter> {
public:
	MovableVisiter() {
		this->Visit(Seq<Movable, Monster, Hero, Building, Projectile>::Type, VisitInvoker);
	}
	virtual ~MovableVisiter() {}

	virtual void Visit(Movable&){}
	virtual void Visit(Monster&){}
	virtual void Visit(Hero&){}
	virtual void Visit(Building&){}
	virtual void Visit(Projectile&){}

private:
	// Here you can change the name of the Visit method.
	typedef EIN_VISIT_INVOKER( Visit ) VisitInvoker;
};

}

#endif /* EIN_MOVABLEVISITER_H_ */
