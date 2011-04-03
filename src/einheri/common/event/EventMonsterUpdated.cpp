/*
 * EventAddPlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventMonsterUpdated.h"
#include "EventVisitor.h"

namespace ein {

EventMonsterUpdated::EventMonsterUpdated(Monster *monster):monster(monster) {

}

EventMonsterUpdated::~EventMonsterUpdated() {

}

void EventMonsterUpdated::accept(EventVisitor& visitor) const {
    visitor.Visit(*this);
}

}
