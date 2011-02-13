#ifndef EIN_COMMON_CLIENT_PULLWORLD_MESSAGE_H_
#define EIN_COMMON_CLIENT_PULLWORLD_MESSAGE_H_
#include "NetworkMessage.h"

namespace ein {

class Event;

class ClientPullWorldMessage: public  NetworkMessage{
public:
    //Structure
    
    ClientPullWorldMessage():NetworkMessage(NetworkMessage::CLIENT_PULL_WORLD) {};
    ~ClientPullWorldMessage() {};
protected:
    virtual void doGenerate() {
    }
    
    
    virtual void doParse() {
    }

};

}

#endif /* EIN_COMMON_CLIENT_PULLWORLD_MESSAGE_H_ */
