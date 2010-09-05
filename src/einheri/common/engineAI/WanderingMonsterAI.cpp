/*
 * MonsterAI.cpp
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#include "WanderingMonsterAI.h"
#include <math.h>
#include "einheri/common/Timer.h"
#include <SFML/System.hpp>

namespace ein {

WanderingMonsterAI::WanderingMonsterAI(Monster *monster) :
    MonsterAI(monster) {
    nextComputeTime = Timer::get().GetGameTime()+0.1f;
}

WanderingMonsterAI::~WanderingMonsterAI() {

}

void WanderingMonsterAI::Compute(){
    if(nextComputeTime < Timer::get().GetGameTime()) {

        EinValue newAngle = monster->GetAngle() + sf::Randomizer::Random((float)-M_PI,(float) M_PI);




        monster->SetAngle(newAngle);
        monster->SetSpeed(Vector(cos(newAngle), sin(newAngle)));

        nextComputeTime+=sf::Randomizer::Random(3, 5);

    }
}

}
