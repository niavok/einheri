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
    completedModel = NULL;
    frameDuration = 1./80.;


}

ClientWorldEngine::~ClientWorldEngine() {

}


void ClientWorldEngine::Start(){
    running = true;
    Launch();
}

void ClientWorldEngine::Stop(){
    running = false;
    Wait();
}

ClientWorldModel *ClientWorldEngine::GetLastCompletedModel() {
    ClientWorldModel *resultModel = completedModel;
    if(resultModel) {
        modelUserCount.insert(std::pair<ClientWorldModel *, int>(resultModel, modelUserCount.at(resultModel)+1));
    }
    return resultModel;
}

void ClientWorldEngine::DisposeModel(ClientWorldModel *model) {
    modelUserCount.insert(std::pair<ClientWorldModel *, int>(model, modelUserCount.at(model)-1));
    if(modelUserCount.at(model) == 0) {
        availableModelQueue.push(model);
    }
}

//Private

void ClientWorldEngine::Run(){
    std::cout<<"ClientWorldEngine started"<<std::endl;

    ClientWorldModel *initialModel = getNewModel();
    editModel = getNewModel();

    completedModel = initialModel;

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
    std::cout<<"ClientWorldEngine clearModels"<<std::endl;
    clearModel();

    std::cout<<"ClientWorldEngine stopped"<<std::endl;
}


ClientWorldModel *ClientWorldEngine::getNewModel() {
    if(availableModelQueue.size() == 0) {
        ClientWorldModel *newModel = new  ClientWorldModel();
        modelUserCount.insert(std::pair<ClientWorldModel *, int>(newModel, 0));
        availableModelQueue.push(newModel);
        modelQueue.push(newModel);
    }

    ClientWorldModel *resultModel = availableModelQueue.front();
    availableModelQueue.pop();
    modelUserCount.insert(std::pair<ClientWorldModel *, int>(resultModel, modelUserCount.at(resultModel)+1));

    return resultModel;

}


void ClientWorldEngine::clearModel() {
    while (!modelQueue.empty()) {
        ClientWorldModel *model = modelQueue.front();

        model->Lock();
        model->Unlock();
        delete model;
        modelQueue.pop();
    }
}

void ClientWorldEngine::frame() {
    std::cout<<"ClientWorldEngine frame"<<std::endl;

    InputEngine * inputEngine = &(app->inputEngine);


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
    }

    syncModel();
}

void ClientWorldEngine::syncModel() {
    ClientWorldModel *nextModel = getNewModel();
    ClientWorldModel *oldModel = completedModel;

    nextModel->Copy(editModel);
    completedModel = editModel;
    editModel = nextModel;
    DisposeModel(oldModel);

}



}
