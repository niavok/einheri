/*
 * PacketDispatcher.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef PACKETDISPATCHER_H_
#define PACKETDISPATCHER_H_

#include <SFML/Network.hpp>

#include "../common/MessageQueue.h"

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
    void dispatchClientUpdateMonsters(sf::Packet *packet);

    void dispatchClientAddHero(sf::Packet *packet);
    void dispatchClientAddHeroes(sf::Packet *packet);

    void dispatchClientPlayerAdded(sf::Packet *packet);
    void dispatchClientHeroAdded(sf::Packet *packet);
    void dispatchClientUpdateHero(sf::Packet *packet);
    void dispatchClientUpdateHeroAimingAngle(sf::Packet *packet);
    void dispatchClientUpdateHeroes(sf::Packet *packet);


    MessageQueue<sf::Packet> packetQueue;


};

}

#endif /* PACKETDISPATCHER_H_ */
