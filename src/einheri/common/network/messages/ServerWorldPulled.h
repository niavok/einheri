#ifndef EIN_COMMON_SERVER_WORLDPULLED_MESSAGE_H_
#define EIN_COMMON_SERVER_WORLDPULLED_MESSAGE_H_
#include "NetworkMessage.h"

namespace ein {

class Event;

class ServerWorldPulledMessage: public  NetworkMessage{
public:
    //Structure
    
    ServerWorldPulledMessage():NetworkMessage(NetworkMessage::SERVER_WORLD_PULLED) {};
    ~ServerWorldPulledMessage() {};
protected:
    virtual void doGenerate() {
    }
    
    
    virtual void doParse() {
    }

};

}

#endif /* EIN_COMMON_SERVER_WORLDPULLED_MESSAGE_H_ */
