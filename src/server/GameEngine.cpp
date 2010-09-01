/*
 * GraphicEngine.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "Application.h"

#include "GameEngine.h"
#include "IdGenerator.h"

#include <iostream>

namespace einheriServer {

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
    std::cout << "SendEvent playerId="<< event.intValues[GameEvent::PLAYER_ID] << std::endl;
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

    std::cout << "processEvent playerId="<< event.intValues[GameEvent::PLAYER_ID] << std::endl;

        if(event.type == GameEvent::ADD_PLAYER) {
            std::cout<<"GameEngine process event ADD_PLAYER"<<std::endl;
            NetworkClient *client = (NetworkClient *) event.objectValues[GameEvent::CLIENT];
            Player * newPlayer = new Player();
            //TODO : delete
            newPlayer->id = IdGenerator::GetId();
            newPlayer->client = client;
            players[newPlayer->id] = newPlayer;

            application->networkEngine.PlayerAdded(client, newPlayer->id);
        }

        if(event.type == GameEvent::ADD_HERO) {
            std::cout<<"GameEngine process event ADD_HERO"<<std::endl;
            int playerId = event.intValues[GameEvent::PLAYER_ID];
            Hero newHero;
            Player *player = players[playerId];
            newHero.parentPlayer = player;

            int heroId = application->worldEngine.AddHero(newHero);
            Hero * hero = application->worldEngine.GetHeroById(heroId);
            player->hero = hero;

            application->networkEngine.HeroAdded(player->client, playerId, heroId);
        }



}

}
