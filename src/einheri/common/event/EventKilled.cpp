/*
 * EventAddPlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventKilled.h"
#include "EventVisitor.h"

namespace ein {

EventKilled::EventKilled(Movable *victim):victim(victim) {

}

EventKilled::~EventKilled() {

}

void EventKilled::accept(EventVisitor& visitor) const {
    visitor.Visit(*this);
}

}
