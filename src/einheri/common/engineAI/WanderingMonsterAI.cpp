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
#include <iostream>

namespace ein {

WanderingMonsterAI::WanderingMonsterAI(Monster *monster) :
    MonsterAI(monster) {
    nextComputeTime = Timer::get().GetGameTime() + 0.1f;
}

WanderingMonsterAI::~WanderingMonsterAI() {

}

void WanderingMonsterAI::Compute() {
    if (nextComputeTime < Timer::get().GetGameTime()) {

        std::cout << "AI position " << monster->GetPosition().getX() << " " << monster->GetPosition().getY() << std::endl;

        EinValue newAngle = monster->GetAngle() + sf::Randomizer::Random((float) -M_PI / 8.f, (float) M_PI / 8.f);

        if (sf::Randomizer::Random(1, 5) == 1) {
            //The monster is affray an try to go to center
            EinValue homeAngle =atan2(-monster->GetPosition().getX(),monster->GetPosition().getY()) -  M_PI/2.f;

            std::cout << "AI angle " << monster->GetAngle() << " " << newAngle << " " << homeAngle << std::endl;

            newAngle = newAngle * 0.5 + homeAngle * 0.5;

            std::cout << "AI newangle " << newAngle << std::endl;

        }

        monster->SetAngle(newAngle);
        monster->SetSpeed(Vector(cos(newAngle), sin(newAngle)));

        nextComputeTime += sf::Randomizer::Random(1.f, 3.f);

    }
}

}
