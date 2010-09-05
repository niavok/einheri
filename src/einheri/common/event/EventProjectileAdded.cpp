/*
 * EventAddPlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EventProjectileAdded.h"
#include "EventVisitor.h"

namespace ein {

EventProjectileAdded::EventProjectileAdded(Projectile *projectile):projectile(projectile) {

}

EventProjectileAdded::~EventProjectileAdded() {

}

void EventProjectileAdded::accept(EventVisitor& visitor) const {
    visitor.Visit(*this);
}

}
