/*
 * ClientWorldModel.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "WorldModel.h"


namespace einheri {



WorldModel::WorldModel() {
}

WorldModel::~WorldModel() {
}

void WorldModel::Lock(){
    lock.Lock();
}

void WorldModel::Unlock() {
    lock.Unlock();
}


}
