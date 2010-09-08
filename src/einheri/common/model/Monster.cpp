/*
 * Projectile.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "Monster.h"

namespace ein {

Monster::Monster() {
    SetName("Unnamed monster");
    std::cout<<"Monster::Monster "<<this<<std::endl;
}

Monster::~Monster() {
    // TODO Auto-generated destructor stub
}

}
