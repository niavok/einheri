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

namespace einheriServer {

Application::Application():
 gameEngine(this),
 networkEngine(this),
 networkNotifier(this),
 worldEngine(this){


}

Application::~Application(){
}

void Application::Run() {



    worldEngine.Start();
    gameEngine.Start();
    networkEngine.Start();
    networkNotifier.Start();


    for(int i = 0; i < 10000; i++) {
        Monster monster;
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
    gameEngine.Stop();
    worldEngine.Stop();
    std::cout<<"exit"<<std::endl;

     return;

}

}
