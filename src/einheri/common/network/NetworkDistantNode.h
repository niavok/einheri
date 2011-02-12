/*
 * EngineNetwork.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_COMMON_NETWORKDISTANTNODE_H_
#define EIN_COMMON_NETWORKDISTANTNODE_H_

#include <SFML/Network.hpp>

namespace ein {

class Event;

class NetworkDistantNode {
public:
    NetworkDistantNode();
    virtual ~NetworkDistantNode();


    void Send(sf::Packet &packet);
    void SetSocket(sf::SocketTCP socket);

private:
    sf::SocketTCP socket;
};

}

#endif /* EIN_COMMON_NETWORKDISTANTNODE_H_ */
