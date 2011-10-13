/*
 * Projectile.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "Hero.h"

namespace ein {

Hero::Hero() {
    SetName("Unnamed hero");
    SetNeedReportingCollision(true);
    SetRadius(0.4);
	SetType(HERO);
}

Hero::~Hero() {

}

}
