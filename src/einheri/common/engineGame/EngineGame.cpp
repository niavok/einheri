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
#include <math.h>
#include "einheri/common/event/EventHeroAdded.h"

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
    //std::cout << "Real " << Timer::get().GetRealTime() << std::endl;
    //std::cout << "Game " << Timer::get().GetGameTime() << std::endl;
    if (Timer::get().GetRealTime() > plop) {
        /*if (plop % 2 == 1) {
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
         }*/
        plop++;
    }

    if (manager->GetGameModel()->GetPlayers().empty()) {
        Player * player = new Player();
        manager->GetGameModel()->AddPlayer(player);
        Hero * hero = new Hero();
        manager->GetModel()->AddHero(hero);

        player->setHero(hero);
        manager->AddEvent(new EventHeroAdded(hero));
    } else {
        Player * player = manager->GetGameModel()->GetPlayers().front();
        Hero * hero = player->getHero();

        if (player->getWantMove()) {
            EinValue moveAngle = player->getWantedAngle();
            EinValue speedFactor = player->getWantedSpeed() * 0.02;
            hero->SetSpeed(Vector(cos(moveAngle) * speedFactor, sin(moveAngle) * speedFactor));
        } else {
            hero->SetSpeed(Vector(0, 0));
        }

        Vector cursor = manager->GetCameraModel()->Pick(manager->GetInputModel()->GetMouse());

        double heroX = hero->GetPosition().getX();
        double heroY = hero->GetPosition().getY();

        double angleX = cursor.getX() - heroX;
        double angleY = cursor.getY() - heroY;

        double aimingAngle = atan2(angleY, angleX);

        hero->SetAngle(aimingAngle);

    }

}

}
