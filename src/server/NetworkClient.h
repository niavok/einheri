/*
 * NetworkClient.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef NETWORKCLIENT_H_
#define NETWORKCLIENT_H_

#include <SFML/Network.hpp>


namespace einheri {


class NetworkClient {
public:
    NetworkClient();
    virtual ~NetworkClient();


    void Send(sf::Packet &packet);
    void SetSocket(sf::SocketTCP socket);

private:
    sf::Mutex sendLock;
    sf::SocketTCP socket;
};

}

#endif /* NETWORKCLIENT_H_ */
