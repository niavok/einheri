/*
 * Projectile.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "Projectile.h"

namespace ein {

Projectile::Projectile() {
    SetName("Unnamed projectile");
    SetNeedReportingCollision(true);
}

Projectile::~Projectile() {

}

}
