/*
 * EngineGame.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineGame.h"
#include <einheri/common/Event.h>
#include <iostream>
#include "einheri/common/Timer.h"
#include <einheri/common/event/EventWindowClose.h>
#include <einheri/common/GameManager.h>

namespace ein {

EngineGame::EngineGame(GameManager* manager) :
    Engine(manager) {
}

EngineGame::~EngineGame() {
}

void EngineGame::Apply(const Event& /*event*/) {
}

int plop = 0;
void EngineGame::Frame() {
    std::cout << "Real " << Timer::get().GetRealTime() << std::endl;
    std::cout << "Game " << Timer::get().GetGameTime() << std::endl;
    if (Timer::get().GetRealTime() > plop) {
        if (plop % 2 == 1) {
            Timer::get().PauseGame();
            std::cout << "pause" << std::endl;
            std::cout << "Real " << Timer::get().GetRealTime() << std::endl;
            std::cout << "Game " << Timer::get().GetGameTime() << std::endl;
            std::cout << "" << std::endl;
        } else {
            Timer::get().StartGame();
            std::cout << "start" << std::endl;
            std::cout << "Real " << Timer::get().GetRealTime() << std::endl;
            std::cout << "Game " << Timer::get().GetGameTime() << std::endl;
            std::cout << "" << std::endl;
        }
        plop++;
    }
    if (plop == 10) {
        manager->AddEvent(new EventWindowClose());
    }

}

}
