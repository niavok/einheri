/*
 * GraphicEngine.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "Application.h"

#include "GraphicEngine.h"
#include "ClientWorldModel.h"
#include "Hero.h"

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

static GLuint index;

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

    gluPerspective(45.f, h, 0.1f, 500.f);

    index = glGenLists(1);

    // compile the display list, store a triangle in it
    glNewList(index, GL_COMPILE);
    glBegin(GL_TRIANGLES);
                glColor3f(0,1,1);
                glVertex3f(0.05f, 0.f, 0.f);
                glColor3f(0,1,0);
                glVertex3f(-0.025f,  0.043f, 0.f);
                glVertex3f(-0.025f,  -0.043f, 0.f);
            glEnd();
    glEndList();


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


}

bool GraphicEngine::Paint() {


    float currentTime = clock.GetElapsedTime();
    if(currentTime - lastFrameClock > frameDuration) {
        lastFrameClock=currentTime;


        //std::cout<<"GraphicEngine get modelToDraw"<<std::endl;
        modelToDraw = application->clientWorldEngine.worldModel;
        //std::cout<<"GraphicEngine modelToDraw"<<modelToDraw<<std::endl;
        if(modelToDraw) {
            clearView();

            configureCamera();

            paintGround();

            paintCorpses();
            paintDecorations();
            paintMonsters();
            paintHeroes();
            paintProjectiles();
            paintEffects();

        }
        //std::cout<<"end draw"<<modelToDraw<<std::endl;

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
    glTranslatef(0.f, 0.f, -25.f);

}

void GraphicEngine::paintGround(){
    glBegin(GL_LINES);
                glColor3f(1,0,0);
                glVertex3f(-10.f, -10.f, 0.f);
                glVertex3f(10.f, -10.f, 0.f);
                glVertex3f(10.f, -10.f, 0.f);
                glVertex3f(10.f, 10.f, 0.f);
                glVertex3f(10.f, 10.f, 0.f);
                glVertex3f(-10.f, 10.f, 0.f);
                glVertex3f(-10.f, 10.f, 0.f);
                glVertex3f(-10.f, -10.f, 0.f);

    glEnd();
}
void GraphicEngine::paintCorpses(){

}
void GraphicEngine::paintDecorations(){

}

void GraphicEngine::paintMonsters(){

    application->clientWorldEngine.worldModel->mutexMonsters.Lock();

    std::map<int, Monster *>::const_iterator it;

    for(it = modelToDraw->GetMonsters().begin(); it != modelToDraw->GetMonsters().end(); ++it) {

        glPushMatrix();
        Monster *monster = it->second;
        glTranslatef( monster->positionX, monster->positionY, 0);
        //std::cout<<"paint monster "<<monster->id<<" "<<monster->positionX<<" "<<monster->positionY<<std::endl;

        glRotatef(monster->angle*180/PI,0,0,1);

        glCallList(index);


        glPopMatrix();
    }

    //std::cout<<"paint monsters end"<<modelToDraw->GetMonsters().size()<<std::endl;

    application->clientWorldEngine.worldModel->mutexMonsters.Unlock();


}

void GraphicEngine::paintHeroes(){

    //std::cout<<"paint heroes"<<std::endl;


    std::map<int, Hero *>::const_iterator it;

    for(it = modelToDraw->GetHeroes().begin(); it != modelToDraw->GetHeroes().end(); it ++) {
        glPushMatrix();
        Hero *hero = it->second;
        glTranslatef( hero->positionX, hero->positionY, 0);
        glRotatef(hero->angle*180/PI,0,0,1);
        glBegin(GL_TRIANGLES);
            glColor3f(1,0,1);
            glVertex3f(0.5f, 0.f, 0.f);
            glColor3f(1,0,0);
            glVertex3f(-0.25f,  0.43f, 0.f);
            glVertex3f(-0.25f,  -0.43f, 0.f);
        glEnd();
        glPopMatrix();
    }



}
void GraphicEngine::paintProjectiles(){

}
void GraphicEngine::paintEffects(){

}


}
