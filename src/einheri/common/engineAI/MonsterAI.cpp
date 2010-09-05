/*
 * MonsterAI.cpp
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#include "MonsterAI.h"

namespace ein {

MonsterAI::MonsterAI(GameManager *manager, Monster *monster) :
    monster(monster),
    manager(manager) {
}

MonsterAI::~MonsterAI() {

}

}
