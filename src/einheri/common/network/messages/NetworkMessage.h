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
        SERVER_HELLO
    };
    
    NetworkMessage(MessageType type);
    
    //No virtual destructor, don't make new in messages !
    ~NetworkMessage();
    
    
    
    virtual void Generate(sf::Packet* packet);
    
    virtual void Parse(sf::Packet* packet);
    
    static MessageType ParseMessageType(sf::Packet* packet);
    
protected:
    
    MessageType type;
    sf::Packet* p;

    virtual void doGenerate() = 0;
    virtual void doParse() = 0;
};

}

#endif /* EIN_COMMON_NETWORKMESSAGE_H_ */
