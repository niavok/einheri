/*
 * EventWindowClose.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventWindowResized.h"
#include "EventVisitor.h"

namespace ein {

EventWindowResized::EventWindowResized(Vector size):size(size) {
}

EventWindowResized::~EventWindowResized() {
}

void EventWindowResized::accept(EventVisitor& visitor) const {
    visitor.Visit(*static_cast<const EventWindowResized*>(this));
}

}
