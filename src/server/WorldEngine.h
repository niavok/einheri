/*
 * ClientWorldEngine.h
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */

#ifndef WORLDENGINE_H_
#define WORLDENGINE_H_

#include <SFML/System.hpp>
#include <queue>
#include "WorldModel.h"
#include "NetworkNotifier.h"

namespace einheri {


class WorldEngine : private sf::Thread {
public:
    WorldEngine(Application *application);
    virtual ~WorldEngine();

    void Start();
    void Stop();

    int AddMonster(Monster monster);

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

    sf::Mutex monsterQueueLock;
    std::queue<Monster *> monsterQueue;





};

}

#endif /* WORLDENGINE_H_ */
