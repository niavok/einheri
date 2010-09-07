/*
 * ProjectileController.cpp
 *
 *  Created on: 6 sept. 2010
 *      Author: fred
 */

#include "PlasmaBallController.h"

namespace ein {

PlasmaBallController::PlasmaBallController(GameManager *manager):ProjectileController(manager) {

}

PlasmaBallController::~PlasmaBallController() {

}

bool PlasmaBallController::processCollision(const EventObjectCollision& /*event*/) {
    return false;
}


}
