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

namespace ein {

EngineScenario::EngineScenario(GameManager* manager) :
    Engine(manager) {
}

EngineScenario::~EngineScenario() {
}

void EngineScenario::Apply(const Event& /*event*/) {
}

double  newMonsterWave = 3;
void EngineScenario::Frame() {
    //std::cout << "Real " << Timer::get().GetRealTime() << std::endl;
    //
    if (Timer::get().GetGameTime() > newMonsterWave) {
        newMonsterWave += 3;
        Monster *monster = new Monster();
        monster->SetPosition(Vector(2,3));
        manager->GetModel()->AddMonster(monster);
        std::cout << "The monster arrived ! Fly, you fools!" << std::endl;
        manager->AddEvent(new EventMonsterAdded(monster));
    }


}

}
