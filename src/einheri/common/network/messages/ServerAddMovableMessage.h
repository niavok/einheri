#ifndef EIN_COMMON_SERVER_ADD_MONSTER_MESSAGE_H_
#define EIN_COMMON_SERVER_ADD_MONSTER_MESSAGE_H_
#include "NetworkMessage.h"
#include <einheri/common/model/Monster.h>

namespace ein {


class ServerAddMovableMessage: public  NetworkMessage{
public:
    //Structure
    int movableId;    
    std::string movableName;
    EinValue angle;
    Vector position;
    EinValue radius;
    Vector speed;
    Vector targetedSpeed;

    ServerAddMovableMessage():NetworkMessage(NetworkMessage::SERVER_ADD_MOVABLE) {};
    
    ServerAddMovableMessage(Movable *movable):NetworkMessage(NetworkMessage::SERVER_ADD_MOVABLE) {
        this->movableId = movable->GetId();
        this->movableName = movable->GetName();
        this->angle =  movable->GetAngle();
        this->position = movable->GetPosition();
        this->radius = movable->GetRadius();
        this->speed = movable->GetSpeed();
        this->targetedSpeed = movable->GetTargetedSpeed();
        
    };
    
    ~ServerAddMovableMessage() {};
    
protected:
    virtual void doGenerate() {
        (*p)<<movableId<<movableName<<angle<<position<<radius<<speed<<targetedSpeed;
    }
    
    
    virtual void doParse() {
        (*p)>>movableId>>movableName>>angle>>position>>radius>>speed>>targetedSpeed;
    }

};

}

#endif /* EIN_COMMON_SERVER_ADD_MONSTER_MESSAGE_H_ */
