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

GraphicEngine::GraphicEngine(Application *application) {
    this->application = application;
    modelToDraw = NULL;
    frameDuration = 1. / 80.;
}

GraphicEngine::~GraphicEngine() {
    // TODO Auto-generated destructor stub
}

static GLuint index;

void GraphicEngine::Init() {

    // Set color and depth clear value
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // Disable Z-buffer for 2d
    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);

    Resize(application->app->GetWidth(), application->app->GetHeight());

    index = glGenLists(1);

    // compile the display list, store a triangle in it
    glNewList(index, GL_COMPILE);
    glBegin(GL_TRIANGLES);
    glColor3f(0, 1, 1);
    glVertex3f(0.1f, 0.f, 0.f);
    glColor3f(0, 1, 0);
    glVertex3f(-0.05f, 0.086f, 0.f);
    glVertex3f(-0.05f, -0.086f, 0.f);
    glEnd();
    glEndList();

    lastFrameClock = clock.GetElapsedTime();
}

void GraphicEngine::Resize(int width, int height) {
    glViewport(0, 0, width, height);

    double h = 1;

    if (application->app->GetHeight() != 0) {
        h = (double) application->app->GetWidth() / (double) application->app->GetHeight();
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /*float L; // Longueur entre les 2 plans de coupe verticaux
     float H; // Hauteur entre les 2 plans de coupe horizontaux
     if (w<=h)
     {
     H=(GLfloat) (10*h/w);
     L=10.0;
     }
     else
     {
     H=10.0;
     L=(GLfloat) (10*w/h);
     }*/
    //gluOrtho2D(-(double)width/2,(double)width/2,-(double)height/2,(double)height/2);

    double zoom = 8;
    gluOrtho2D(-zoom * h, zoom * h, -zoom, zoom);
    //gluPerspective(45.f, h, 0.1f, 500.f);


}

bool GraphicEngine::Paint() {

    float currentTime = clock.GetElapsedTime();
    if (currentTime - lastFrameClock > frameDuration) {
        lastFrameClock = currentTime;

        clearView();

        configureCamera();

        modelToDraw = application->clientWorldEngine.worldModel;
        if (modelToDraw) {


            paintGround();

            paintCorpses();
            paintDecorations();
            paintMonsters();
            paintHeroes();
            paintProjectiles();
            paintEffects();

        }


        paintCursor();

        return true;
    } else {
        return false;
    }

}

//Private

void GraphicEngine::clearView() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicEngine::configureCamera() {

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void GraphicEngine::paintGround() {
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
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
void GraphicEngine::paintCorpses() {

}
void GraphicEngine::paintDecorations() {

}

void GraphicEngine::paintMonsters() {

    application->clientWorldEngine.worldModel->mutexMonsters.Lock();

    std::map<int, Monster *>::const_iterator it;

    for (it = modelToDraw->GetMonsters().begin(); it != modelToDraw->GetMonsters().end(); ++it) {

        glPushMatrix();
        Monster *monster = it->second;
        glTranslatef(monster->positionX, monster->positionY, 0);
        //std::cout<<"paint monster "<<monster->id<<" "<<monster->positionX<<" "<<monster->positionY<<std::endl;

        glRotatef(monster->angle * 180 / PI, 0, 0, 1);

        glCallList(index);

        glPopMatrix();
    }

    //std::cout<<"paint monsters end"<<modelToDraw->GetMonsters().size()<<std::endl;

    application->clientWorldEngine.worldModel->mutexMonsters.Unlock();

}

void GraphicEngine::paintHeroes() {

    //std::cout<<"paint heroes"<<std::endl;


    std::map<int, Hero *>::const_iterator it;

    for (it = modelToDraw->GetHeroes().begin(); it != modelToDraw->GetHeroes().end(); it++) {
        glPushMatrix();
        Hero *hero = it->second;
        glTranslatef(hero->positionX, hero->positionY, 0);
        glRotatef(hero->angle * 180 / PI, 0, 0, 1);
        glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 1);
        glVertex3f(0.25f, 0.f, 0.f);
        glColor3f(1, 0, 0);
        glVertex3f(-0.125f, 0.215f, 0.f);
        glVertex3f(-0.125f, -0.215f, 0.f);
        glEnd();
        glPopMatrix();
    }

}
void GraphicEngine::paintProjectiles() {

}

void GraphicEngine::paintEffects() {

}

void GraphicEngine::paintCursor() {

    Vect2<int> mousePoint = application->inputEngine.GetMouse();

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, application->app->GetWidth(), application->app->GetHeight(), 0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    int length = 20;
    int thickness = 3;

    glTranslatef(mousePoint.getX(), mousePoint.getY(), 0);
    glBegin(GL_TRIANGLES);
    glColor4f(1, 0, 0, 0.8);
    glVertex3f(-thickness, length, 0.f);
    glVertex3f(thickness, length, 0.f);
    glColor4f(1, 1, 0, 0.5);
    glVertex3f(0, 0, 0.f);

    glColor4f(1, 0, 0, 0.8);
    glVertex3f(-thickness, -length, 0.f);
    glVertex3f(thickness, -length, 0.f);
    glColor4f(1, 1, 0, 0.5);
    glVertex3f(0, 0, 0.f);

    glColor4f(1, 0, 0, 0.8);
    glVertex3f(length, thickness, 0.f);
    glVertex3f(length, -thickness, 0.f);
    glColor4f(1, 1, 0, 0.5);
    glVertex3f(0, 0, 0.f);

    glColor4f(1, 0, 0, 0.8);
    glVertex3f(-length, thickness, 0.f);
    glVertex3f(-length, -thickness, 0.f);
    glColor4f(1, 1, 0, 0.5);
    glVertex3f(0, 0, 0.f);

    glEnd();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);

    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

}

Vect2<double> GraphicEngine::Pick(int x, int y) {
    //TODO
    return Vect2<double> (x, y);
}

}
