/*
 * GraphicEngine.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "GraphicEngine.h"
#include <iostream>

namespace einheri {

GraphicEngine::GraphicEngine(){
    // TODO Auto-generated constructor stub

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
    gluPerspective(90.f, 1.f, 1.f, 500.f);

}


void GraphicEngine::Resize(int width, int height){
    glViewport(0, 0, width, height);
}

void GraphicEngine::Paint() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.f, 0.f, -200.f);
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {

            for(int k = 0; k < 15; k++) {
        glPushMatrix();
        glTranslatef( i*25 -180, j*25-180, -k*25);
        glRotatef(clock.GetElapsedTime() * 50, 1.f, 0.f, 0.f);
        glRotatef(clock.GetElapsedTime() * 30, 0.f, 1.f, 0.f);
        glRotatef(clock.GetElapsedTime() * 90, 0.f, 0.f, 1.f);
        glBegin(GL_QUADS);
            glColor3f(1,0,0);
            glVertex3f(-5.f, -5.f, -5.f);
            glVertex3f(-5.f,  5.f, -5.f);
            glVertex3f( 5.f,  5.f, -5.f);
            glVertex3f( 5.f, -5.f, -5.f);

            glColor3f(1,1,1);
            glVertex3f(-5, -5, 5);
            glVertex3f(-5,  5, 5);
            glVertex3f( 5,  5, 5);
            glVertex3f( 5, -5, 5);

            glColor3f(1,1,0);
            glVertex3f(-5, -5, -5);
            glVertex3f(-5,  5, -5);
            glVertex3f(-5,  5,  5);
            glVertex3f(-5, -5,  5);

            glColor3f(1,0,1);

            glVertex3f(5, -5, -5);
            glVertex3f(5,  5, -5);
            glVertex3f(5,  5,  5);
            glVertex3f(5, -5,  5);

            glColor3f(0,0,1);

            glVertex3f(-5, -5,  5);
            glVertex3f(-5, -5, -5);
            glVertex3f( 5, -5, -5);
            glVertex3f( 5, -5,  5);

            glColor3f(0,0.4,1);
            glVertex3f(-5, 5,  5);
            glVertex3f(-5, 5, -5);
            glVertex3f( 5, 5, -5);
            glVertex3f( 5, 5,  5);

        glEnd();
        glPopMatrix();
            }
        }
    }

}



}
