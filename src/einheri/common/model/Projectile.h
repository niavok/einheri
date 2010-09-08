/*
 * Projectile.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_PROJECTILE_H_
#define EHR_COMMON_PROJECTILE_H_

#include "Movable.h"

namespace ein {

class Projectile: public ein::Movable {
public:
    EIN_DEFINE_VISITABLE()
public:
    Projectile();
    virtual ~Projectile();

    void SetShooter(Movable* shooter) {this->shooter = shooter; }
    Movable* GetShooter() { return shooter; }

private:
    Movable* shooter;
};

}

#endif /* EHR_COMMON_PROJECTILE_H_ */
