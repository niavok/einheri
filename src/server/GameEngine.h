/*
 * GameEngine.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef SERVER_GAMEENGINE_H_
#define SERVER_GAMEENGINE_H_

#include <SFML/System.hpp>

#include "GameEvent.h"
#include "MessageQueue.h"
#include "Player.h"

namespace einheriServer {

class Application;


class GameEngine : private sf::Thread {
public:
    GameEngine(Application *application);
    virtual ~GameEngine();

    void Start();
    void Stop();

    void SendEvent(GameEvent event);

private:
    bool running;
    Application *application;

    virtual void Run();

    virtual void processEvent();

    MessageQueue<GameEvent> events;
    std::map<int, Player *> players;


};

}

#endif /* GAMEENGINE_H_ */
