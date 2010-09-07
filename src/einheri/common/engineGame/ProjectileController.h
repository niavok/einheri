/*
 * ProjectileController.h
 *
 *  Created on: 6 sept. 2010
 *      Author: fred
 */

#ifndef EIN_PROJECTILECONTROLLER_H_
#define EIN_PROJECTILECONTROLLER_H_
#include <einheri/common/GameManager.h>
#include <einheri/common/event/EventObjectCollision.h>

namespace ein {

class ProjectileController {
public:
    ProjectileController(GameManager *manager);
    virtual ~ProjectileController();

    virtual bool processCollision(const Projectile* projectile, Movable *collider) = 0;

protected:
    GameManager *manager;
};

}

#endif /* EIN_PROJECTILECONTROLLER_H_ */
