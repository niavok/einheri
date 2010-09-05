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
    nextComputeTime = Timer::get().GetGameTime()+1;
}

WanderingMonsterAI::~WanderingMonsterAI() {

}

void WanderingMonsterAI::Compute(){
    if(nextComputeTime < Timer::get().GetGameTime()) {

        EinValue newAngle = monster->GetAngle() + sf::Randomizer::Random((float)-M_PI/4.f,(float) M_PI/4.f);




        monster->SetAngle(newAngle);
        monster->SetSpeed(Vector(cos(newAngle), sin(newAngle)));

        nextComputeTime+=sf::Randomizer::Random(3, 5);

    }
}

}
