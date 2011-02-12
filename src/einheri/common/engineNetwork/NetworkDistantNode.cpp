
#include "NetworkDistantNode.h"



namespace ein {

NetworkDistantNode::NetworkDistantNode() {

}

NetworkDistantNode::~NetworkDistantNode() {

}

void NetworkDistantNode::SetSocket(sf::SocketTCP socket) {
    this->socket = socket;
}

void NetworkDistantNode::Send(sf::Packet &packet) {
    socket.Send(packet);
}


}
