/*
 * EngineNetwork.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "NetworkMessage.h"
#include <einheri/common/Event.h>

namespace ein {

NetworkMessage::NetworkMessage(MessageType type){
    this->type = type;
}

NetworkMessage::~NetworkMessage() {
}

void NetworkMessage::Generate(sf::Packet* packet)
{
    p = packet;
    (*p)<<type;
    doGenerate();
}

void NetworkMessage::Parse(sf::Packet* packet)
{
    p = packet;
    doParse();
}

NetworkMessage::MessageType NetworkMessage::ParseMessageType(sf::Packet* packet)
{
    int commandTypeInt;
    (*packet) >> commandTypeInt;

    return (NetworkMessage::MessageType) commandTypeInt;   
}

//Type conversion
sf::Packet& operator <<(sf::Packet& Packet, const Vector& C)
{
    return Packet << C.x << C.y;
}

sf::Packet& operator >>(sf::Packet& Packet, Vector& C)
{
    return Packet >> C.x >> C.y;
}





}
