/*
 * EventAddPlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventHeroAdded.h"
#include "EventVisitor.h"

namespace ein {

EventHeroAdded::EventHeroAdded(Hero *hero):hero(hero) {

}

EventHeroAdded::~EventHeroAdded() {

}

void EventHeroAdded::accept(EventVisitor& visitor) const {
    visitor.Visit(*this);
}

}
