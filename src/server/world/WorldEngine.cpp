/*
 * ClientWorldEngine.cpp
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */
#include <iostream>
#include <math.h>

#include "WorldEngine.h"
#include "../Application.h"
#include "../IdGenerator.h"

namespace einheriServer {

WorldEngine::WorldEngine(Application *application) {
    this->app = application;
    frameDuration = 1. / 60.;

}

WorldEngine::~WorldEngine() {
    std::cout << "WorldEngine destructor" << std::endl;
}

void WorldEngine::Start() {
    running = true;
    Launch();
}

void WorldEngine::Stop() {
    running = false;
    Wait();
}

Monster *WorldEngine::AddMonster(Monster monster) {
    Monster *newMonster = new Monster(monster);
    newMonster->GenerateId();

    monsterQueueLock.Lock();

    monsterQueue.push(newMonster);

    monsterQueueLock.Unlock();

    return newMonster;
}

Hero * WorldEngine::AddHero(Hero hero) {
    Hero *newHero = new Hero(hero);
    newHero->GenerateId();

    heroQueueLock.Lock();

    heroQueue.push(newHero);

    heroQueueLock.Unlock();

    return newHero;
}

//Private

void WorldEngine::Run() {
    std::cout << "WorldEngine started" << std::endl;

    lastFrameClock = clock.GetElapsedTime();

    while (running) {
        float currentTime = clock.GetElapsedTime();
        if (currentTime - lastFrameClock > frameDuration) {
            lastFrameClock += frameDuration;
            frame();
        } else {
            sf::Sleep(frameDuration - (currentTime - lastFrameClock));
        }

    }

    std::cout << "WorldEngine stopped" << std::endl;
}

void WorldEngine::frame() {

    model.Lock();

    addNewElements();

    computeHeroesSpeed();
    computeHeroesPosition();
    app->networkNotifier.Flush();
    computeHeroesAimingAngle();

    computeMonsterSpeed();
    computeMonsterPosition();
    computeMonsterTarget();
    app->networkNotifier.Flush();

    computeProjectilesPosition();

    model.Unlock();

}

void WorldEngine::addNewElements() {
    monsterQueueLock.Lock();

    while (!monsterQueue.empty()) {
        Monster * monster = monsterQueue.front();
        monsterQueue.pop();
        model.monsters.insert(std::pair<int, Monster *>(monster->id, monster));

        app->networkNotifier.AddMonster(monster);
    }

    monsterQueueLock.Unlock();

    heroQueueLock.Lock();

    while (!heroQueue.empty()) {
        Hero * hero = heroQueue.front();
        heroQueue.pop();
        model.heroes.insert(std::pair<int, Hero *>(hero->id, hero));

        app->networkNotifier.AddHero(hero);
    }

    heroQueueLock.Unlock();
}

Hero *WorldEngine::GetHeroById(int id) {
    Hero *result = NULL;
    heroQueueLock.Lock();

    if(model.heroes.count(id) > 0) {
        result = model.heroes.at(id);
    }

    heroQueueLock.Unlock();
    return result;
}

void WorldEngine::computeMonsterTarget() {
    std::map<int, Monster *>::iterator it;
    for (it = model.monsters.begin(); it != model.monsters.end(); ++it) {
        Monster *monster = it->second;
        bool monsterChanged = false;

        if (monster->positionX > 10 && monster->speedX > 0) {
            monster->speedX = -monster->speedX;
            monsterChanged = true;
        }

        if (monster->positionX < -10 && monster->speedX < 0) {
            monster->speedX = -monster->speedX;
            monsterChanged = true;
        }

        if (monster->positionY > 10 && monster->speedY > 0) {
            monster->speedY = -monster->speedY;
            monsterChanged = true;
        }

        if (monster->positionY < -10 && monster->speedY < 0) {
            monster->speedY = -monster->speedY;
            monsterChanged = true;
        }

        if (monsterChanged) {
            //std::cout<<"WorldEngine monster "<<monster->id<<" change"<<std::endl;
            app->networkNotifier.StackUpdateMonster(monster);
        }
    }

}

void WorldEngine::computeMonsterSpeed() {

}

void WorldEngine::computeMonsterPosition() {
    std::map<int, Monster *>::iterator it;
    for (it = model.monsters.begin(); it != model.monsters.end(); ++it) {
        Monster *monster = it->second;
        monster->positionX = monster->positionX + monster->speedX * frameDuration;
        monster->positionY = monster->positionY + monster->speedY * frameDuration;
        //std::cout<<"WorldEngine monster "<<monster->id<<" speed is "<<monster->speedX<<" and new pos is "<<monster->positionX<<std::endl;
    }
}

void WorldEngine::computeHeroesAimingAngle() {
    std::map<int, Hero *>::iterator it;
    for (it = model.heroes.begin(); it != model.heroes.end(); ++it) {
        Hero *hero = it->second;

        if (hero->aimingAngle != hero->playerAimingAngle) {
            hero->aimingAngle = hero->playerAimingAngle;
            app->networkNotifier.UpdateHeroAimingAngle(hero);
        }
    }
}

void WorldEngine::computeHeroesSpeed() {
    std::map<int, Hero *>::iterator it;
    for (it = model.heroes.begin(); it != model.heroes.end(); ++it) {
        Hero *hero = it->second;
        bool heroChanged = false;

        double newSpeedX = 0;
        double newSpeedY = 0;

        if (hero->playerMove) {
            newSpeedX = cos(hero->playerAngle) * hero->playerSpeed * 0.01;
            newSpeedY = sin(hero->playerAngle) * hero->playerSpeed * 0.01;
        }

        if (newSpeedX != hero->speedX || newSpeedY != hero->speedY) {
            hero->speedX = newSpeedX;
            hero->speedY = newSpeedY;
            heroChanged = true;
        }

        if (heroChanged) {
            //std::cout<<"WorldEngine monster "<<monster->id<<" change"<<std::endl;
            app->networkNotifier.StackUpdateHero(hero);
        }
    }
}

void WorldEngine::computeHeroesPosition() {
    std::map<int, Hero *>::iterator it;
    for (it = model.heroes.begin(); it != model.heroes.end(); ++it) {
        Hero *hero = it->second;
        hero->positionX = hero->positionX + hero->speedX * frameDuration;
        hero->positionY = hero->positionY + hero->speedY * frameDuration;
        //std::cout<<"WorldEngine monster "<<monster->id<<" speed is "<<monster->speedX<<" and new pos is "<<monster->positionX<<std::endl;
    }
}

void WorldEngine::computeProjectilesPosition() {
    std::map<int, Projectile *>::iterator it;
    for (it = model.projectiles.begin(); it != model.projectiles.end(); ++it) {
        Projectile *projectile = it->second;
        projectile->positionX = projectile->positionX + projectile->speedX * frameDuration;
        projectile->positionY = projectile->positionY + projectile->speedY * frameDuration;
        //std::cout<<"WorldEngine monster "<<monster->id<<" speed is "<<monster->speedX<<" and new pos is "<<monster->positionX<<std::endl;
    }
}

}
