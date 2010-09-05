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

        if(sf::Randomizer::Random(1,5) == 1) {
            //The monster is affray an try to go to center

            if(monster->GetPosition().getX() > 0 && monster->GetSpeed().getX() > 0) {
                monster->SetSpeed(Vector(-monster->GetSpeed().getX(),monster->GetSpeed().getY()));
            }

            if(monster->GetPosition().getX() < 0 && monster->GetSpeed().getX() < 0) {
                monster->SetSpeed(Vector(-monster->GetSpeed().getX(),monster->GetSpeed().getY()));
            }

            if(monster->GetPosition().getY() > 0 && monster->GetSpeed().getY() > 0) {
                monster->SetSpeed(Vector(monster->GetSpeed().getX(),-monster->GetSpeed().getY()));
            }

            if(monster->GetPosition().getY() < 0 && monster->GetSpeed().getY() < 0) {
                monster->SetSpeed(Vector(monster->GetSpeed().getX(),-monster->GetSpeed().getY()));
            }
        }



        nextComputeTime+=sf::Randomizer::Random(3.f, 5.f);

    }
}

}
