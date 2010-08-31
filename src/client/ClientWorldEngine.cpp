/*
 * ClientWorldEngine.cpp
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */
#include <iostream>
#include "ClientWorldEngine.h"
#include "InputEngine.h"
#include "Application.h"
typedef std::pair<std::string, std::string> TStrStrPair;
#include <math.h>

namespace einheri {

ClientWorldEngine::ClientWorldEngine(Application *application) {
    app = application;
    frameDuration = 1./60.;

    worldModel = new ClientWorldModel();

}

ClientWorldEngine::~ClientWorldEngine() {
    delete worldModel;
}


void ClientWorldEngine::Start(){
    running = true;
    Launch();
}

void ClientWorldEngine::Stop(){
    running = false;
    Wait();
}

//Private

void ClientWorldEngine::Run(){
    std::cout<<"ClientWorldEngine started"<<std::endl;


    lastFrameClock = clock.GetElapsedTime();

    while(running) {
        float currentTime = clock.GetElapsedTime();
        if(currentTime - lastFrameClock > frameDuration) {
            lastFrameClock+=frameDuration;
            frame();
        }else {
            //std::cout<<"ClientWorldEngine sleep "<<frameDuration - (currentTime - lastFrameClock)<<std::endl;
            sf::Sleep(frameDuration - (currentTime - lastFrameClock));
        }

    }



    std::cout<<"ClientWorldEngine stopped"<<std::endl;
}

void ClientWorldEngine::frame() {
    //std::cout<<"ClientWorldEngine frame"<<std::endl;

    /*InputEngine * inputEngine = &(app->inputEngine);


    bool left = inputEngine->IsMoveLeft();
    bool right = inputEngine->IsMoveRight();
    bool up = inputEngine->IsMoveUp();
    bool down = inputEngine->IsMoveDown();

    double PI = 3.14159265;

    std::cout<<"ClientWorldEngine key state "<<left<<" "<<right<<" "<<up<<" "<<down<<" "<<std::endl;

    if(left && !right && !up && !down) {
        editModel->heroes.angle = PI;
    }

    if(left && !right && up && !down) {
        editModel->heroes.angle = 3*PI/4;
    }

    if(!left && !right && up && !down) {
        editModel->heroes.angle = PI/2;
    }

    if(!left && right && up && !down) {
        editModel->heroes.angle = PI/4;
    }

    if(!left && right && !up && !down) {
        editModel->heroes.angle = 0;
    }

    if(!left && right && !up && down) {
        editModel->heroes.angle = -PI/4;
    }

    if(!left && !right && !up && down) {
        editModel->heroes.angle = -PI/2;
    }

    if(left && !right && !up && down) {
        editModel->heroes.angle = -3*PI/4;
    }

    double speed = 0.01;

    if(left || right || up || down) {
        editModel->heroes.positionX+= cos(editModel->heroes.angle)*speed;
        editModel->heroes.positionY+= sin(editModel->heroes.angle)*speed;
    }*/



    worldModel->mutexMonsters.Lock();
    computeMonsterSpeed();
    computeMonsterPosition();
    worldModel->mutexMonsters.Unlock();

}

void ClientWorldEngine::computeMonsterSpeed(){
    std::map<int, Monster *>::const_iterator it;

    /*for(it = editModel->monsters.begin(); it != editModel->monsters.end(); it ++) {
        Monster *monster = it->second;
        monster->speedX = 1;
        monster->speedY = 0.5;
    }*/
}

void ClientWorldEngine::computeMonsterPosition(){
    std::map<int, Monster *>::const_iterator it;

    //std::cout<<"ClientWorldEngine computeMonsterPosition "<<editModel->GetMonsters().size()<<std::endl;

    worldModel->GetMonsters().size();

    for(it = worldModel->GetMonsters().begin(); it != worldModel->GetMonsters().end(); ++it) {
        Monster *monster = it->second;
        monster->positionX = monster->positionX + monster->speedX * frameDuration;
        monster->positionY = monster->positionY + monster->speedY * frameDuration;
        //std::cout<<"ClientWorldEngine monster "<<monster->id<<" speed is "<<monster->speedX<<" and new pos is "<<monster->positionX<<std::endl;
    }
    //std::cout<<"ClientWorldEngine computeMonsterPosition end"<<editModel->GetMonsters().size()<<std::endl;
}


}
