#ifndef EIN_COMMON_SERVER_UPDATE_MONSTER_MESSAGE_H_
#define EIN_COMMON_SERVER_UPDATE_MONSTER_MESSAGE_H_
#include "NetworkMessage.h"
#include <einheri/common/model/Monster.h>

namespace ein {


class ServerUpdateMovableMessage: public  NetworkMessage{
public:
    //Structure
    int movableId;    
    EinValue angle;
    Vector position;
    Vector speed;
    Vector targetedSpeed;

    ServerUpdateMovableMessage():NetworkMessage(NetworkMessage::SERVER_UPDATE_MOVABLE) {};
    
    ServerUpdateMovableMessage(Movable *movable):NetworkMessage(NetworkMessage::SERVER_UPDATE_MOVABLE) {
        this->movableId = movable->GetId();
        this->angle =  movable->GetAngle();
        this->position = movable->GetPosition();
        this->speed = movable->GetSpeed();
        this->targetedSpeed = movable->GetTargetedSpeed();
        
    };
    
    virtual ~ServerUpdateMovableMessage() {};
    
protected:
    virtual void doGenerate() {
        (*p)<<movableId<<angle<<position<<speed<<targetedSpeed;
    }
    
    
    virtual void doParse() {
        (*p)>>movableId>>angle>>position>>speed>>targetedSpeed;
    }

};

}

#endif /* EIN_COMMON_SERVER_ADD_MONSTER_MESSAGE_H_ */
