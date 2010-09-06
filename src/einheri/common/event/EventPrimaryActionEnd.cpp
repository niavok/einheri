/*
 * EventAddPlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventPrimaryActionEnd.h"
#include "EventVisitor.h"

namespace ein {

EventPrimaryActionEnd::EventPrimaryActionEnd(Player *player):player(player) {
}

EventPrimaryActionEnd::~EventPrimaryActionEnd() {
}

void EventPrimaryActionEnd::accept(EventVisitor& visitor) const {
    visitor.Visit(*this);
}

}
