/*
 * Application.cpp
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */

#include <SFML/System.hpp>

#include "Application.h"
#include "WorldEngine.h"
#include "NetworkEngine.h"
#include "Monster.h"

#include <iostream>

namespace einheri {

Application::Application():
 networkEngine(this),
 gameEngine(this),
 networkNotifier(this),
 worldEngine(this){


}

Application::~Application(){
}

void Application::Run() {



    worldEngine.Start();
    networkEngine.Start();
    networkNotifier.Start();

    for(int i = 0; i < 20000; i++) {
        einheri::Monster monster;
        monster.positionX = sf::Randomizer::Random(-1.f, 1.f);
        monster.positionY = sf::Randomizer::Random(-1.f, 1.f);

        monster.speedX = sf::Randomizer::Random(-1.f, 1.f)+1.f;
        monster.speedY = sf::Randomizer::Random(-1.f, 1.f)+2.f;
        worldEngine.AddMonster(monster);
    }

    while(true) {
        sf::Sleep(10);
    }

    networkNotifier.Stop();
    networkEngine.Stop();
    worldEngine.Stop();
    std::cout<<"exit"<<std::endl;

     return;

}

}
