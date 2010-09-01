/*
 * NetworkClient.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef SERVER_NETWORKCLIENT_H_
#define SERVER_NETWORKCLIENT_H_

#include <SFML/Network.hpp>


namespace einheriServer {


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
