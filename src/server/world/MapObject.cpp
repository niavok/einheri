/*
 * Monster.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "MapObject.h"
#include "../IdGenerator.h"

namespace einheriServer {

MapObject::MapObject() {
    speedX = 0;
    speedY = 0;
    positionX = 0;
    positionY = 0;
    angle = 0;
}

MapObject::~MapObject() {
}

void MapObject::GenerateId() {
    id = IdGenerator::GetId();
}

}
