/*
 * ClientWorldEngine.h
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */

#ifndef CLIENTWORLDENGINE_H_
#define CLIENTWORLDENGINE_H_

#include <SFML/Window.hpp>
#include "ClientWorldModel.h"

#include <queue>
#include <map>


namespace einheri {

class Application;


class ClientWorldEngine : private sf::Thread {
public:
    ClientWorldEngine(Application *application);
    virtual ~ClientWorldEngine();

    void Start();
    void Stop();



    ClientWorldModel *worldModel;

private:
    Application *app;
    float frameDuration;
    float lastFrameClock;
    sf::Clock clock;
    virtual void Run();
    bool running;
    void frame();

    void computeMonsterSpeed();
    void computeMonsterPosition();
    void computeHeroesPosition();

    void updateHeroMovement();

    double previousAngle;
    bool previousMove;
    double previousSpeed;
};

}

#endif /* CLIENTWORLDENGINE_H_ */
