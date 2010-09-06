/*
 * EventAddPlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventObjectCollision.h"
#include "EventVisitor.h"

namespace ein {

EventObjectCollision::EventObjectCollision(Movable *object1, Movable *object2):object1(object1), object2(object2) {

}

EventObjectCollision::~EventObjectCollision() {

}

void EventObjectCollision::accept(EventVisitor& visitor) const {
    visitor.Visit(*this);
}

}
