/*
 * EventAddPlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventKill.h"
#include "EventVisitor.h"

namespace ein {

EventKill::EventKill(Movable *victim):victim(victim) {

}

EventKill::~EventKill() {

}

void EventKill::accept(EventVisitor& visitor) const {
    visitor.Visit(*this);
}

}
