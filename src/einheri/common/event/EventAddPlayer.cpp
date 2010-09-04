/*
 * EventAddPlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventAddPlayer.h"
#include "EventVisitor.h"

namespace ein {

EventAddPlayer::EventAddPlayer() {
    // TODO Auto-generated constructor stub

}

EventAddPlayer::~EventAddPlayer() {
    // TODO Auto-generated destructor stub
}

void EventAddPlayer::accept(EventVisitor& visitor) const {
    visitor.Visit(*this);
}

}
