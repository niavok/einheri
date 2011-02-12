/*
 * EventQuitGame.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventQuitGame.h"
#include "EventVisitor.h"

namespace ein {

EventQuitGame::EventQuitGame() {
}

EventQuitGame::~EventQuitGame() {
}

void EventQuitGame::accept(EventVisitor& visitor) const {
    visitor.Visit(*static_cast<const EventQuitGame*>(this));
}

}
