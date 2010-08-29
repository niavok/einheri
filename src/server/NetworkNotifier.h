/*
 * NetworkNotifier.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef NETWORKNOTIFIER_H_
#define NETWORKNOTIFIER_H_

#include "SFML/Network.hpp"
#include "NetworkEngine.h"
#include "MessageQueue.h"
#include "Monster.h"

namespace einheri {

class NetworkNotifier : private sf::Thread {
public:
    NetworkNotifier(Application *application);
    virtual ~NetworkNotifier();





    void AddMonster(Monster *monster);
    void AddMonsters(std::vector<Monster *>);
    void UpdateMonster(Monster *monster);
    void Start();
    void Stop();

private:
    Application *app;
    virtual void Run();
    bool running;
    MessageQueue<sf::Packet *> packetQueue;
};

}

#endif /* NETWORKNOTIFIER_H_ */
