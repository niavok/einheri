
#include "NetworkDistantNode.h"



namespace ein {

NetworkDistantNode::NetworkDistantNode() {

}

NetworkDistantNode::~NetworkDistantNode() {

}

void NetworkDistantNode::SetSocket(sf::SocketTCP socket) {
    this->socket = socket;
}

void NetworkDistantNode::Send(NetworkMessage* message) {
    sf::Packet packet;
    message->Generate(&packet);
    socket.Send(packet);
    delete message;
}


}
