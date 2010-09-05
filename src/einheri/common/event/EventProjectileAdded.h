/*
 * EventAddPlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENT_PROJECTILE_ADDED_H_
#define EIN_EVENT_PROJECTILE_ADDED_H_

#include <einheri/common/Event.h>
#include <einheri/common/model/Hero.h>
#include <einheri/common/model/Projectile.h>

namespace ein {

class EventVisitor;

class EventProjectileAdded : public Event{
public:
    EventProjectileAdded(Projectile *projectile);
    virtual ~EventProjectileAdded();

    void accept(EventVisitor& visitor)const;

    Projectile *GetProjectile() const { return projectile; };

private:
    Projectile *projectile;
};

}

#endif /* EIN_EVENT_PROJECTILE_ADDED_H_ */
