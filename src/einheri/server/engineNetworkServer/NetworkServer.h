/*
 * EngineNetwork.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_NETWORSERVERK_H_
#define EIN_NETWORSERVERK_H_

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <einheri/common/network/messages/NetworkMessage.h>
#include <einheri/common/Player.h>
#include <einheri/common/network/NetworkDistantNode.h>
#include "NetworkServerSender.h"


namespace ein {

class EngineNetworkServer;
    
class NetworkServer : private sf::Thread {
public:
    NetworkServer(EngineNetworkServer *engine);
    virtual ~NetworkServer();

    void Start();
    void Stop();

    void SendMessageToAll(NetworkMessage* message);
    void SendMessageToPlayer(NetworkMessage* message, Player* player);
    void SendMessageToNetworkClient(NetworkMessage* message, Player* player);

    void ProcessMessages();
    
private:
    virtual void Run();
    void Dispatch ( sf::Packet packet, NetworkDistantNode* sender);
    void Send(NetworkDistantNode* sender, NetworkMessage* message);
    bool running;
    std::map<sf::SocketTCP, NetworkDistantNode *> clients;
    NetworkServerSender serverSender;
    
    //Recevied message and sender queue
    sf::Mutex queueMutex;
    std::queue<NetworkMessage*> messageQueue;
    std::queue<NetworkDistantNode*> clientQueue;

    //Parent engine
    EngineNetworkServer *engine;

};

}

#endif /* EIN_NETWORSERVERK_H_ */
