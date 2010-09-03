/*
 * GraphicEngine.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "Application.h"

#include "GameEngine.h"
#include "IdGenerator.h"

#include "world/Bullet.h"

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

            Hero * hero = application->worldEngine.AddHero(newHero);
            player->hero = hero;

            application->networkEngine.HeroAdded(player->client, playerId, hero->id);
        }

        if(event.type == GameEvent::HERO_USE_MAIN_ACTION) {
                    std::cout<<"GameEngine process event HERO_USE_MAIN_ACTION"<<std::endl;
                    int heroId = event.intValues[GameEvent::HERO_ID];

                    application->worldEngine.model.Lock();

                    Hero * hero = application->worldEngine.GetHeroById(heroId);

                    Bullet * newBullet = new Bullet();
                    newBullet->GenerateId();
                    newBullet->shooter = hero;
                    newBullet->positionX = hero->positionX;
                    newBullet->positionY = hero->positionY;

                    application->worldEngine.model.projectiles.insert(std::pair<int, Projectile *>(newBullet->id, newBullet));

                    application->worldEngine.model.Unlock();



                    application->networkNotifier.AddProjectile(newBullet);
                }


}

}
