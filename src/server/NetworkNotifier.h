/*
 * NetworkNotifier.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef NETWORKNOTIFIER_H_
#define NETWORKNOTIFIER_H_

#include <vector>
#include <SFML/Network.hpp>
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
    void StackUpdateMonster(Monster *monster);
    void UpdateMonsters(std::vector<Monster *>);
    void Flush();
    void Start();
    void Stop();

private:
    sf::Mutex flushMutext;
    Application *app;
    virtual void Run();
    bool running;
    MessageQueue<sf::Packet *> packetQueue;
    std::vector<Monster *> monstersToUpdate;
};

}

#endif /* NETWORKNOTIFIER_H_ */
