/*
 * GraphicEngine.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "Application.h"

#include "GraphicEngine.h"
#include "ClientWorldModel.h"

#include <iostream>

#define PI 3.14159265

namespace einheri {

GraphicEngine::GraphicEngine(Application *application){
    this->application = application;
    modelToDraw = NULL;
    frameDuration = 1./80.;
}

GraphicEngine::~GraphicEngine() {
    // TODO Auto-generated destructor stub
}

void GraphicEngine::Init() {


    // Set color and depth clear value
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    double h = 1;

    if(application->app->GetHeight() != 0 ){
        h = (double) application->app->GetWidth()/(double) application->app->GetHeight();
    }

    std::cout<<"h "<<h<<std::endl;
    gluPerspective(45.f, h, 0.1f, 500.f);

    lastFrameClock = clock.GetElapsedTime();
}


void GraphicEngine::Resize(int width, int height){
    glViewport(0, 0, width, height);

    double h = 1;

    if(application->app->GetHeight() != 0 ){
        h = (double)application->app->GetWidth()/(double) application->app->GetHeight();
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.f, h, 0.1f, 500.f);

    std::cout<<"h "<<h<<std::endl;
}

bool GraphicEngine::Paint() {


    float currentTime = clock.GetElapsedTime();
    if(currentTime - lastFrameClock > frameDuration) {
        lastFrameClock=currentTime;


        modelToDraw = application->clientWorldEngine.GetLastCompletedModel();

        if(modelToDraw) {
            modelToDraw->Lock();
            clearView();

            configureCamera();

            paintGround();
            paintCorpses();
            paintDecorations();
            paintHeroes();
            paintProjectiles();
            paintEffects();

            modelToDraw->Unlock();

            application->clientWorldEngine.DisposeModel(modelToDraw);

        }

        return true;
    } else {
        return false;
    }



}


//Private

void GraphicEngine::clearView(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicEngine::configureCamera(){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.f, 0.f, -10.f);

}

void GraphicEngine::paintGround(){

}
void GraphicEngine::paintCorpses(){

}
void GraphicEngine::paintDecorations(){

}
void GraphicEngine::paintHeroes(){

    std::cout<<"paint heroes"<<std::endl;
    glPushMatrix();
    glTranslatef( modelToDraw->heroes.positionX, modelToDraw->heroes.positionY, 0);
    glRotatef(modelToDraw->heroes.angle*180/PI,0,0,1);
    glBegin(GL_TRIANGLES);
        glColor3f(1,0,1);
        glVertex3f(1.0f, 0.f, 0.f);
        glColor3f(1,0,0);
        glVertex3f(-0.5f,  0.86f, 0.f);
        glVertex3f(-0.5f,  -0.86f, 0.f);
    glEnd();

}
void GraphicEngine::paintProjectiles(){

}
void GraphicEngine::paintEffects(){

}


}
