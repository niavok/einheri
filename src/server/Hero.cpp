/*
 * Heroes.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */
#include "Hero.h"

#include "Player.h"
#include "IdGenerator.h"

namespace einheriServer {

Hero::Hero() {
    positionX = 0;
    positionY = 0;
    angle = 0;
}

Hero::~Hero() {
}

void Hero::GenerateId() {
    id = IdGenerator::GetId();
}

}
