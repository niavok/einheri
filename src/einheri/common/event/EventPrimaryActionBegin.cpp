/*
 * EventAddPlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventPrimaryActionBegin.h"
#include "EventVisitor.h"

namespace ein {

EventPrimaryActionBegin::EventPrimaryActionBegin(Player *player):player(player) {
}

EventPrimaryActionBegin::~EventPrimaryActionBegin() {
}

void EventPrimaryActionBegin::accept(EventVisitor& visitor) const {
    visitor.Visit(*this);
}

}
