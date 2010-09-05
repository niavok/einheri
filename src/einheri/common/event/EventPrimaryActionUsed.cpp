/*
 * EventAddPlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventPrimaryActionUsed.h"
#include "EventVisitor.h"

namespace ein {

EventPrimaryActionUsed::EventPrimaryActionUsed(Player *player):player(player) {
}

EventPrimaryActionUsed::~EventPrimaryActionUsed() {
}

void EventPrimaryActionUsed::accept(EventVisitor& visitor) const {
    visitor.Visit(*this);
}

}
