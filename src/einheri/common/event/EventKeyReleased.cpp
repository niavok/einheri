/*
 * EventWindowClose.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventKeyReleased.h"
#include "EventVisitor.h"

namespace ein {

EventKeyReleased::EventKeyReleased(sf::Key::Code keyCode):keyCode(keyCode) {
}

EventKeyReleased::~EventKeyReleased() {
}

void EventKeyReleased::accept(EventVisitor& visitor) const {
    visitor.Visit(*static_cast<const EventKeyReleased*>(this));
}

}
