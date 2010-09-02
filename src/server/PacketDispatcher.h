/*
 * PacketDispatcher.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef SERVER_PACKETDISPATCHER_H_
#define SERVER_PACKETDISPATCHER_H_

#include <SFML/Network.hpp>

#include "../common/MessageQueue.h"
#include "NetworkClient.h"

namespace einheriServer {

class Application;

class PacketDispatcher : private sf::Thread {
public:
    PacketDispatcher(Application * application);
    virtual ~PacketDispatcher();

    void Dispatch(sf::Packet packet, NetworkClient *client);
    void Start();
    void Stop();

private:
    Application * app;
    virtual void Run();
    bool running;

    void executePacket();

    MessageQueue<sf::Packet> packetQueue;
    MessageQueue<NetworkClient *> socketQueue;


    void dispatchServerHello(sf::Packet *packet, NetworkClient *client);
    void dispatchServerGetWorld(sf::Packet *packet, NetworkClient *client);
    void dispatchServerGetAddPlayer(sf::Packet *packet, NetworkClient *client);
    void dispatchServerGetAddHero(sf::Packet *packet, NetworkClient *client);
    void dispatchServerSetPlayerName(sf::Packet *packet, NetworkClient *client);
    void dispatchServerUpdateHeroMovement(sf::Packet *packet, NetworkClient *client);

};

}

#endif /* PACKETDISPATCHER_H_ */
