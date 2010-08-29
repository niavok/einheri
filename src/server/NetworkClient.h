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

    void SetSocket(sf::SocketTCP socket);
    sf::SocketTCP socket;
private:

};

}

#endif /* NETWORKCLIENT_H_ */
