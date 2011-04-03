/*
 * MonsterAI.cpp
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#include "EatTheHeroMonsterAI.h"
#include <math.h>
#include "einheri/common/Timer.h"
#include <SFML/System.hpp>
#include <iostream>
#include <einheri/common/event/EventMonsterUpdated.h>

namespace ein {

EatTheHeroMonsterAI::EatTheHeroMonsterAI(GameManager *manager, Monster *monster) :
    MonsterAI(manager, monster) {
    nextComputeTime = Timer::get().GetGameTime() + 0.1f;
}

EatTheHeroMonsterAI::~EatTheHeroMonsterAI() {

}

void EatTheHeroMonsterAI::Compute() {
    if (nextComputeTime < Timer::get().GetGameTime()) {

        Hero *freshMeat = manager->GetModel()->GetHeroes().front();

        if(freshMeat) {

            EinValue meatAngle =atan2(freshMeat->GetPosition().getX()-monster->GetPosition().getX(),monster->GetPosition().getY()-freshMeat->GetPosition().getY()) -  M_PI/2.f;

            monster->SetAngle(meatAngle);
            monster->SetTargetedSpeed(Vector(cos(meatAngle), sin(meatAngle)));

            
            manager->AddEvent(new EventMonsterUpdated(monster));
        }

        nextComputeTime += 1.0;

    }
}

}
