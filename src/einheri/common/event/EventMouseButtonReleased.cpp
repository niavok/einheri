/*
 * EventWindowClose.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventMouseButtonReleased.h"
#include "EventVisitor.h"
#include <SFML/Window.hpp>

using sf::Mouse::Button;

namespace ein {

EventMouseButtonReleased::EventMouseButtonReleased(sf::Mouse::Button button):button(button) {
}

EventMouseButtonReleased::~EventMouseButtonReleased() {
}

void EventMouseButtonReleased::accept(EventVisitor& visitor) const {
    visitor.Visit(*static_cast<const EventMouseButtonReleased*>(this));
}

}
