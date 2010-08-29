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

    ClientWorldModel *GetLastCompletedModel();
    void DisposeModel(ClientWorldModel *model);

    ClientWorldModel *editModel;

    sf::Mutex syncLock;

private:
    Application *app;
    float frameDuration;
    float lastFrameClock;
    sf::Clock clock;
    virtual void Run();
    bool running;
    void frame();


    void syncModel();
    void clearModel();

    void computeMonsterSpeed();
    void computeMonsterPosition();

    ClientWorldModel * getNewModel();


    ClientWorldModel *completedModel;




    std::queue<ClientWorldModel *> availableModelQueue;
    std::queue<ClientWorldModel *> modelQueue;
    std::map<ClientWorldModel *, int> modelUserCount;

};

}

#endif /* CLIENTWORLDENGINE_H_ */
