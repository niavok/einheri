/*
 * WorldDrawer.cpp
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#include "WorldDrawer.h"
#include <math.h>
#include <SFML/Graphics.hpp>
#include <einheri/utils/Log.h>

namespace ein {

WorldDrawer::WorldDrawer(GameManager *manager):manager(manager) {


}

WorldDrawer::~WorldDrawer() {

}

void WorldDrawer::Init() {

    // Set color and depth clear value
        glClearDepth(1.f);
        glClearColor(0.f, 0.f, 0.f, 0.f);

        // Disable Z-buffer for 2d
        glDisable(GL_DEPTH_TEST);
        glDepthMask(GL_FALSE);


    monsterListIndex = glGenLists(1);

        // compile the monster display list, store a triangle in it
        glNewList(monsterListIndex, GL_COMPILE);
        glBegin(GL_TRIANGLES);
        glColor3f(0, 1, 1);
        glVertex3f(0.5f, 0.f, 0.f);
        glColor3f(0, 1, 0);
        glVertex3f(-0.25f, 0.43f, 0.f);
        glVertex3f(-0.25f, -0.43f, 0.f);
        glEnd();
        glEndList();
}


void WorldDrawer::Draw() {

    clearView();

    configureCamera();



    paintGround();

    paintCorpses();
    paintDecorations();
    paintProjectiles();
    paintMonsters();
    paintHeroes();

    paintEffects();


    paintCursor();



}

void WorldDrawer::Resize(Vector newWindowSize) {

    windowSize = newWindowSize;

    glViewport(0, 0, windowSize.getX(), windowSize.getY());

    double h = 1;

    if (windowSize.getY() != 0) {
        h = windowSize.getX() / windowSize.getY();
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    gluOrtho2D(-(manager->GetCameraModel()->GetDistance() * h)/2., (manager->GetCameraModel()->GetDistance() * h)/2., -manager->GetCameraModel()->GetDistance()/2., manager->GetCameraModel()->GetDistance()/2.);

}

//Private

void WorldDrawer::clearView() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void WorldDrawer::configureCamera() {

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void WorldDrawer::paintGround() {
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
void WorldDrawer::paintCorpses() {

}
void WorldDrawer::paintDecorations() {

}

void WorldDrawer::paintMonsters() {


    std::list<Monster *>::const_iterator it;

    for (it = manager->GetModel()->GetMonsters().begin(); it != manager->GetModel()->GetMonsters().end(); ++it) {

        glPushMatrix();
        Monster *monster = *it;
        glTranslatef(monster->GetPosition().getX(),monster->GetPosition().getY(), 0);

        glRotatef(monster->GetAngle() * 180 / M_PI, 0, 0, 1);

        glCallList(monsterListIndex);

        glPopMatrix();
    }

}

void WorldDrawer::paintHeroes() {

    std::list<Hero *>::const_iterator it;

    for (it = manager->GetModel()->GetHeroes().begin(); it != manager->GetModel()->GetHeroes().end(); it++) {
        glPushMatrix();
        Hero *hero = *it;
        glTranslatef(hero->GetPosition().getX(), hero->GetPosition().getY(), 0);
        glRotatef(hero->GetAngle() * 180 / M_PI, 0, 0, 1);
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
void WorldDrawer::paintProjectiles() {

        std::list<Projectile *>::const_iterator it;

        for (it = manager->GetModel()->GetProjectiles().begin(); it != manager->GetModel()->GetProjectiles().end(); ++it) {
            glPushMatrix();
            Projectile *projectile = *it;
            glTranslatef(projectile->GetPosition().getX(), projectile->GetPosition().getY(), 0);

            glRotatef(projectile->GetAngle() * 180 / M_PI, 0, 0, 1);

            glBegin(GL_TRIANGLES);
                    glColor3f(1, 1, 1);
                    glVertex3f(-0.545f, 0.f, 0.f);
                    glColor4f(1, 1, 1, 0.0);
                    glVertex3f(0.0225f, 0.020f, 0.f);
                    glVertex3f(0.0225f, -0.020f, 0.f);
                    glEnd();

            glPopMatrix();
        }


}

void WorldDrawer::paintEffects() {

}

void WorldDrawer::paintCursor() {

    Vector mousePoint = manager->GetInputModel()->GetMouse();

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, manager->GetInputModel()->GetWindowSize().getX(), manager->GetInputModel()->GetWindowSize().getY(), 0);

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


}
