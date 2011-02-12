#ifndef EIN_COMMON_SERVER_HELLO_MESSAGE_H_
#define EIN_COMMON_SERVER_HELLO_MESSAGE_H_
#include "NetworkMessage.h"

namespace ein {

class Event;

class ServerHelloMessage: public  NetworkMessage{
public:
    //Structure
    int majorProtocolVersion;
    int minorProtocolVersion;
    std::string description;

    ServerHelloMessage():NetworkMessage(NetworkMessage::SERVER_HELLO) {};
    
protected:
    virtual void doGenerate() {
        majorProtocolVersion = NetworkMessage::MAJOR_PROTOCOL_VERSION;
        minorProtocolVersion = NetworkMessage::MINOR_PROTOCOL_VERSION;
        description = "Einheri server alpha - x86_64 GNU/Linux - ubuntu 10.10";
        
        (*p)<<majorProtocolVersion<<minorProtocolVersion<<description;
    }
    
    
    virtual void doParse() {
        (*p)>>majorProtocolVersion>>minorProtocolVersion>>description;
    }

};

}

#endif /* EIN_COMMON_SERVER_HELLO_MESSAGE_H_ */
