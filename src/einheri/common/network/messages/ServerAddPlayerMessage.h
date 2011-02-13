#ifndef EIN_COMMON_SERVER_ADD_PLAYER_MESSAGE_H_
#define EIN_COMMON_SERVER_ADD_PLAYER_MESSAGE_H_
#include "NetworkMessage.h"

namespace ein {

class Event;

class ServerAddPlayerMessage: public  NetworkMessage{
public:
    //Structure
    int playerId;
    bool isLocal;
    std::string playerName;

    ServerAddPlayerMessage():NetworkMessage(NetworkMessage::SERVER_ADD_PLAYER) {};
    
    ServerAddPlayerMessage(int playerId, bool isLocal, std::string playerName):NetworkMessage(NetworkMessage::SERVER_ADD_PLAYER) {
        this->playerId = playerId;
        this->isLocal = isLocal;
        this->playerName = playerName;
    };
    
    ~ServerAddPlayerMessage() {};
    
protected:
    virtual void doGenerate() {
        (*p)<<playerId<<isLocal<<playerName;
    }
    
    
    virtual void doParse() {
        (*p)>>playerId>>isLocal>>playerName;
    }

};

}

#endif /* EIN_COMMON_SERVER_ADD_PLAYER_MESSAGE_H_ */
