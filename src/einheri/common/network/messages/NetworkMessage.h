/*
 * EngineNetwork.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_COMMON_NETWORKMESSAGE_H_
#define EIN_COMMON_NETWORKMESSAGE_H_
#include <string>
#include <SFML/Network.hpp>
#include <einheri/common/Vect2.h>
namespace ein {

class Event;

class NetworkMessage{
public:
    
    static const int MAJOR_PROTOCOL_VERSION = 1;
    static const int MINOR_PROTOCOL_VERSION = 0;
    
    
    enum MessageType {
        SERVER_HELLO = 0,
        SERVER_ADD_MOVABLE,
        SERVER_ADD_MOVABLES,
        SERVER_UPDATE_MOVABLE,
        SERVER_UPDATE_MOVABLES,
        SERVER_ADD_PLAYER,
        SERVER_WORLD_PULLED,
        
        CLIENT_HELLO = 1000000000,
        CLIENT_PULL_WORLD,
        CLIENT_CREATE_PLAYER
    };
    
    NetworkMessage(MessageType type);
    virtual ~NetworkMessage();
    
    
    
    virtual void Generate(sf::Packet* packet);
    
    virtual void Parse(sf::Packet* packet);
    
    static MessageType ParseMessageType(sf::Packet* packet);
    
    MessageType type;
    
protected:
    
    
    sf::Packet* p;

    virtual void doGenerate() = 0;
    virtual void doParse() = 0;
    
  
};

    //Type conversion
    sf::Packet& operator <<(sf::Packet& Packet, const Vector& C);
    /*{
        return Packet << C.x << C.y;
    }*/

    sf::Packet& operator >>(sf::Packet& Packet, Vector& C);
    /*{
        return Packet >> C.x >> C.y;
    }*/


}

#endif /* EIN_COMMON_NETWORKMESSAGE_H_ */
