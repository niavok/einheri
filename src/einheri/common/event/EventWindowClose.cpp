/*
 * EventWindowClose.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventWindowClose.h"
#include "EventVisitor.h"

namespace ein {

EventWindowClose::EventWindowClose() {
    // TODO Auto-generated constructor stub

}

EventWindowClose::~EventWindowClose() {
    // TODO Auto-generated destructor stub
}

void EventWindowClose::accept(EventVisitor& visitor) const {
    visitor.Visit(*static_cast<const EventWindowClose*>(this));
}

}
