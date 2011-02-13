/*
 * EngineNetwork.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_NETWORKCLIENT_H_
#define EIN_NETWORKCLIENT_H_

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <einheri/common/network/messages/NetworkMessage.h>
#include <einheri/common/Player.h>
#include <einheri/common/network/NetworkDistantNode.h>
#include "NetworkClientSender.h"


namespace ein {

class EngineNetworkClient;
    
class NetworkClient: private sf::Thread {
public:
    NetworkClient(EngineNetworkClient *engine);
    virtual ~NetworkClient();

    void Start();
    void Stop();

    void Send(NetworkMessage* message);
    void ProcessMessages();
    
    
private:
    virtual void Run();
    void Dispatch ( sf::Packet packet);
    void processServerHelloMessage(sf::Packet* arg1);
    bool running;
    sf::SocketTCP clientSocket;
    NetworkClientSender clientSender;

    //Recevied message and sender queue
    sf::Mutex queueMutex;
    std::queue<NetworkMessage*> messageQueue;
    
    //Parent engine
    EngineNetworkClient *engine;

};

}

#endif /* EIN_NETWORKCLIENT_H_ */
