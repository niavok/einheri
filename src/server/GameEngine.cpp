/*
 * GraphicEngine.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "Application.h"

#include "GameEngine.h"

#include <iostream>

namespace einheri {

GameEngine::GameEngine(Application *application){
    this->application = application;
}

GameEngine::~GameEngine() {

}
void GameEngine::Start(){
    running = true;
    Launch();
}

void GameEngine::Stop(){
    running = false;
    GameEvent endEvent;
    events.PushMessage(endEvent);
    Wait();
}

void GameEngine::SendEvent(GameEvent event) {
    events.PushMessage(event);
}


//Private

void GameEngine::Run(){
    std::cout<<"GameEngine started"<<std::endl;


    while(running) {
        processEvent();
    }

    std::cout<<"GameEngine stopped"<<std::endl;
}

void GameEngine::processEvent(){
    GameEvent event = events.PopMessage();


}

}
