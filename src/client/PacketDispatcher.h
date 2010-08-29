/*
 * PacketDispatcher.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef PACKETDISPATCHER_H_
#define PACKETDISPATCHER_H_

#include <SFML/Network.hpp>

#include "MessageQueue.h"

namespace einheri {

class Application;

class PacketDispatcher : private sf::Thread {
public:
    PacketDispatcher(Application *application);
    virtual ~PacketDispatcher();

    void Dispatch(sf::Packet packet, sf::SocketTCP socket);
    void Start();
    void Stop();

private:
    Application *app;
    virtual void Run();
    bool running;

    void executePacket();

    void dispatchClientHello(sf::Packet *packet);
    void dispatchClientAddMonster(sf::Packet *packet);
    void dispatchClientAddMonsters(sf::Packet *packet);
    void dispatchClientUpdateMonster(sf::Packet *packet);


    MessageQueue<sf::Packet> packetQueue;


};

}

#endif /* PACKETDISPATCHER_H_ */
