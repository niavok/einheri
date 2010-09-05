/*
 * EventWindowClose.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventWindowCreated.h"
#include "EventVisitor.h"

namespace ein {

EventWindowCreated::EventWindowCreated(sf::RenderWindow *window):window(window) {
}

EventWindowCreated::~EventWindowCreated() {
}

void EventWindowCreated::accept(EventVisitor& visitor) const {
    visitor.Visit(*static_cast<const EventWindowCreated*>(this));
}

}
