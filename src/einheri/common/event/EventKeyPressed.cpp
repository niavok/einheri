/*
 * EventWindowClose.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventKeyPressed.h"
#include "EventVisitor.h"

namespace ein {

EventKeyPressed::EventKeyPressed(sf::Key::Code keyCode):keyCode(keyCode) {
}

EventKeyPressed::~EventKeyPressed() {
}

void EventKeyPressed::accept(EventVisitor& visitor) const {
    visitor.Visit(*static_cast<const EventKeyPressed*>(this));
}

}
