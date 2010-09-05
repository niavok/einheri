/*
 * EventAddPlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventMonsterAdded.h"
#include "EventVisitor.h"

namespace ein {

EventMonsterAdded::EventMonsterAdded(Monster *monster):monster(monster) {

}

EventMonsterAdded::~EventMonsterAdded() {

}

void EventMonsterAdded::accept(EventVisitor& visitor) const {
    visitor.Visit(*this);
}

}
