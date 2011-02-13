#ifndef EIN_COMMON_CLIENT_CREATE_PLAYER_MESSAGE_H_
#define EIN_COMMON_CLIENT_CREATE_PLAYER_MESSAGE_H_
#include "NetworkMessage.h"

namespace ein {

class Event;

class ClientCreatePlayerMessage: public  NetworkMessage{
public:
    //Structure
    std::string playerName;

    ClientCreatePlayerMessage():NetworkMessage(NetworkMessage::CLIENT_CREATE_PLAYER) {
    };
    
    ClientCreatePlayerMessage(std::string playerName):NetworkMessage(NetworkMessage::CLIENT_CREATE_PLAYER) {
        this->playerName = playerName;
    };
    ~ClientCreatePlayerMessage() {};
protected:
    virtual void doGenerate() {
        (*p)<<playerName;
    }
    
    
    virtual void doParse() {
        (*p)>>playerName;
    }

};

}

#endif /* EIN_COMMON_CLIENT_CREATE_PLAYER_MESSAGE_H_ */
