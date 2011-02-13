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

namespace ein {

class Event;

class NetworkMessage{
public:
    
    static const int MAJOR_PROTOCOL_VERSION = 1;
    static const int MINOR_PROTOCOL_VERSION = 0;
    
    
    enum MessageType {
        SERVER_HELLO = 0,
        SERVER_ADD_HERO,
        SERVER_ADD_HEROES,
        SERVER_ADD_MONSTER,
        SERVER_ADD_MONSTERS,
        SERVER_UPDATE_HERO,
        SERVER_UPDATE_HEROES,
        SERVER_UPDATE_MONSTER,
        SERVER_UPDATE_MONSTERS,
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

}

#endif /* EIN_COMMON_NETWORKMESSAGE_H_ */
