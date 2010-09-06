/*
 * EngineGame.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineScenario.h"
#include <einheri/common/Event.h>
#include <iostream>
#include <einheri/common/Timer.h>
#include <einheri/common/event/EventWindowClose.h>
#include <einheri/common/GameManager.h>
#include <einheri/common/event/EventMonsterAdded.h>
#include <math.h>

namespace ein {

EngineScenario::EngineScenario(GameManager* manager) :
    Engine(manager) {
}

EngineScenario::~EngineScenario() {
}

void EngineScenario::Apply(const Event& /*event*/) {
}

double newMonsterWave = 4;
void EngineScenario::Frame() {
    //std::cout << "Real " << Timer::get().GetRealTime() << std::endl;
    //
    if (Timer::get().GetGameTime() > newMonsterWave) {
        newMonsterWave += 1;
        Monster *monster1 = new Monster();
        monster1->SetPosition(Vector(4, 4));
        monster1->SetAngle(M_PI / 4.f);
        monster1->SetName("Balrog");
        manager->GetModel()->AddMonster(monster1);

        Monster *monster2 = new Monster();
        monster2->SetPosition(Vector(4, -4));
        monster2->SetAngle(-M_PI / 4.f);
        monster2->SetName("Gobelin");
        manager->GetModel()->AddMonster(monster2);
        Monster *monster3 = new Monster();
        monster3->SetPosition(Vector(-4, 4));
        monster3->SetAngle(3. * M_PI / 4.);
        monster3->SetName("Orc");
        manager->GetModel()->AddMonster(monster3);
        Monster *monster4 = new Monster();
        monster4->SetPosition(Vector(-4, -4));
        monster4->SetAngle(-3. * M_PI / 4.);
        monster4->SetName("Troll");
        manager->GetModel()->AddMonster(monster4);

        std::cout << "The monster arrived ! Fly, you fools!" << std::endl;
        manager->AddEvent(new EventMonsterAdded(monster1));
        manager->AddEvent(new EventMonsterAdded(monster2));
        manager->AddEvent(new EventMonsterAdded(monster3));
        manager->AddEvent(new EventMonsterAdded(monster4));
    }

}

}
