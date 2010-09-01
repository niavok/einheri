/*
 * Monster.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "Monster.h"
#include "IdGenerator.h"

namespace einheriServer {

Monster::Monster() {
    speedX = 0;
    speedY = 0;
    positionX = 0;
    positionY = 0;
    angle = 0;
}

void Monster::GenerateId() {
    id = IdGenerator::GetId();
}


Monster::~Monster() {
}

}
