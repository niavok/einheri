/*
 * ClientWorldEngine.cpp
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */
#include <iostream>
#include "WorldEngine.h"
#include "Application.h"
#include <math.h>

namespace einheri {

WorldEngine::WorldEngine(Application *application) {
    this->app = application;
    frameDuration = 1./80.;


}

WorldEngine::~WorldEngine() {
    std::cout<<"WorldEngine destructor"<<std::endl;
}


void WorldEngine::Start(){
    running = true;
    Launch();
}

void WorldEngine::Stop(){
    running = false;
    Wait();
}

int WorldEngine::AddMonster(Monster monster){
    Monster *newMonster =new Monster(monster);
    newMonster->GenerateId();

    monsterQueueLock.Lock();

    monsterQueue.push(newMonster);

    monsterQueueLock.Unlock();


    return newMonster->id;
}



//Private

void WorldEngine::Run(){
    std::cout<<"WorldEngine started"<<std::endl;

    lastFrameClock = clock.GetElapsedTime();

    while(running) {
        float currentTime = clock.GetElapsedTime();
        if(currentTime - lastFrameClock > frameDuration) {
            lastFrameClock+=frameDuration;
            frame();
        }else {
            sf::Sleep(frameDuration - (currentTime - lastFrameClock));
        }

    }

    std::cout<<"WorldEngine stopped"<<std::endl;
}


void WorldEngine::frame() {

    model.Lock();

    addNewElements();

    computeMonsterSpeed();
    computeMonsterPosition();
    computeMonsterTarget();

    model.Unlock();

}


void WorldEngine::addNewElements(){
    monsterQueueLock.Lock();

    while(!monsterQueue.empty()) {
        Monster * monster = monsterQueue.front();
        monsterQueue.pop();
        model.monsters.push_back(monster);

        app->networkNotifier.AddMonster(monster);
    }

    monsterQueueLock.Unlock();
}


void WorldEngine::computeMonsterTarget(){
    for(int i = 0; i< model.monsters.size(); i++){
        bool monsterChanged = false;

        Monster *monster = model.monsters[i];
        if(monster->positionX > 10 && monster->speedX > 0 ) {
            monster->speedX = -monster->speedX;
            monsterChanged = true;
        }

        if(monster->positionX < -10 && monster->speedX < 0) {
            monster->speedX = -monster->speedX;
            monsterChanged = true;
        }

        if(monster->positionY > 10 && monster->speedY > 0) {
            monster->speedY = -monster->speedY;
            monsterChanged = true;
        }

        if(monster->positionY < -10 && monster->speedY < 0) {
            monster->speedY = -monster->speedY;
            monsterChanged = true;
        }

        if(monsterChanged) {
             //std::cout<<"WorldEngine monster "<<monster->id<<" change"<<std::endl;
            app->networkNotifier.UpdateMonster(monster);
        }
    }

}

void WorldEngine::computeMonsterSpeed(){

}

void WorldEngine::computeMonsterPosition(){
    for(int i = 0; i< model.monsters.size(); i++){
        Monster *monster = model.monsters[i];
        monster->positionX = monster->positionX + monster->speedX * frameDuration;
        monster->positionY = monster->positionY + monster->speedY * frameDuration;
        //std::cout<<"WorldEngine monster "<<monster->id<<" speed is "<<monster->speedX<<" and new pos is "<<monster->positionX<<std::endl;
    }
}




}
