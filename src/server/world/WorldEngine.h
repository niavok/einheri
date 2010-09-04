/*
 * ClientWorldEngine.h
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */

#ifndef SERVER_WORLDENGINE_H_
#define SERVER_WORLDENGINE_H_

#include <SFML/System.hpp>
#include <queue>
#include "WorldModel.h"
#include "../NetworkNotifier.h"

namespace einheriServer {


class WorldEngine : private sf::Thread {
public:
    WorldEngine(Application *application);
    virtual ~WorldEngine();

    void Start();
    void Stop();

    Monster *AddMonster(Monster monster);
    Hero *AddHero(Hero hero);
    Hero *GetHeroById(int id);
    WorldModel model;


private:
    Application *app;
    float frameDuration;
    float lastFrameClock;
    sf::Clock clock;
    virtual void Run();
    bool running;
    void frame();

    void addNewElements();
    void computeMonsterTarget();
    void computeMonsterSpeed();
    void computeMonsterPosition();

    void computeHeroesSpeed();
    void computeHeroesPosition();
    void computeHeroesAimingAngle();

    void computeProjectilesPosition();


    sf::Mutex monsterQueueLock;
    std::queue<Monster *> monsterQueue;

    sf::Mutex heroQueueLock;
    std::queue<Hero *> heroQueue;




};

}

#endif /* WORLDENGINE_H_ */
