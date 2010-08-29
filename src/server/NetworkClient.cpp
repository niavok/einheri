/*
 * NetworkClient.cpp
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#include "NetworkClient.h"

namespace einheri {

NetworkClient::NetworkClient() {

}

NetworkClient::~NetworkClient() {

}

void NetworkClient::SetSocket(sf::SocketTCP socket) {
    this->socket = socket;
}

}
