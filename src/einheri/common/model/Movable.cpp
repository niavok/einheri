/*
 * Movable.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "Movable.h"

namespace ein {

Movable::Movable() {
    name = "Unnamed movable";
    needReportingCollision = false;
    id = 0;
    position = Vector(0.,0.);
    speed = Vector(0.,0.);
    targetedSpeed = Vector(0.,0.);
    angle = 0.;
    radius = 1;
    alive = true;
}

Movable::~Movable() {
    // TODO Auto-generated destructor stub
}



}
