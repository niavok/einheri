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

namespace ein {

class NetworkClient: private sf::Thread {
public:
    NetworkClient();
    virtual ~NetworkClient();

    void Start();
    void Stop();

    void Send(NetworkMessage* message);
    
private:
    virtual void Run();
    void Dispatch ( sf::Packet packet);
    bool running;
    sf::SocketTCP clientSocket;




};

}

#endif /* EIN_NETWORKCLIENT_H_ */
