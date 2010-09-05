/*
 * EventWindowClose.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventMouseButtonPressed.h"
#include "EventVisitor.h"

namespace ein {

EventMouseButtonPressed::EventMouseButtonPressed(sf::Mouse::Button button):button(button) {
}

EventMouseButtonPressed::~EventMouseButtonPressed() {
}

void EventMouseButtonPressed::accept(EventVisitor& visitor) const {
    visitor.Visit(*static_cast<const EventMouseButtonPressed*>(this));
}

}
