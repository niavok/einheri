/*
 * ProjectileController.h
 *
 *  Created on: 6 sept. 2010
 *      Author: fred
 */

#ifndef EIN_PLASMABALLCONTROLLER_H_
#define EIN_PLASMABALLCONTROLLER_H_
#include <einheri/common/engineGame/ProjectileController.h>
#include "einheri/common/model/PlasmaBall.h"

namespace ein {

class PlasmaBallController : public ProjectileController {
public:
    PlasmaBallController(GameManager *manager);
    virtual ~PlasmaBallController();

    virtual bool processCollision(const Projectile* projectile, Movable *collider);
    void Process(PlasmaBall* plasmaBall, Movable* collider);
};

}

#endif /* EIN_PLASMABALLCONTROLLER_H_ */
