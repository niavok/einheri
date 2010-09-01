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
    if(running) {
        running = false;
        GameEvent endEvent;
        events.PushMessage(endEvent);
        Wait();
    }
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

    std::cout<<"GameEngine process event"<<std::endl;


    if(event.type == GameEvent::CONNECTED_TO_SERVER) {
        std::cout<<"GameEngine process event CONNECTED_TO_SERVER"<<std::endl;
        application->networkEngine.Hello();
    }

    if(event.type == GameEvent::REGISTERED_TO_SERVER) {
            std::cout<<"GameEngine process event REGISTERED_TO_SERVER"<<std::endl;
            application->networkEngine.GetWorld();
            application->networkEngine.AddPlayer();
    }

    if(event.type == GameEvent::PLAYER_ADDED) {
            std::cout<<"GameEngine process event ADD_PLAYER"<<std::endl;
            localPlayer.id = event.intValues[GameEvent::PLAYER_ID];
            application->networkEngine.SetPlayerName(localPlayer.id, "fred");
            application->networkEngine.AddHero(localPlayer.id);
    }

    if(event.type == GameEvent::HERO_ADDED) {
            std::cout<<"GameEngine process event ADD_HERO"<<std::endl;
            if(event.intValues[GameEvent::PLAYER_ID ] == localPlayer.id) {
                localPlayer.heroId =  event.intValues[GameEvent::HERO_ID];
            }
    }



}

}
