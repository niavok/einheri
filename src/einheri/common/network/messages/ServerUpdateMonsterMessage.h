#ifndef EIN_COMMON_SERVER_UPDATE_MONSTER_MESSAGE_H_
#define EIN_COMMON_SERVER_UPDATE_MONSTER_MESSAGE_H_
#include "NetworkMessage.h"
#include <einheri/common/model/Monster.h>

namespace ein {


class ServerUpdateMonsterMessage: public  NetworkMessage{
public:
    //Structure
    int monsterId;    
    EinValue angle;
    Vector position;
    Vector speed;
    Vector targetedSpeed;

    ServerUpdateMonsterMessage():NetworkMessage(NetworkMessage::SERVER_UPDATE_MONSTER) {};
    
    ServerUpdateMonsterMessage(Monster *monster):NetworkMessage(NetworkMessage::SERVER_UPDATE_MONSTER) {
        this->monsterId = monster->GetId();
        this->angle =  monster->GetAngle();
        this->position = monster->GetPosition();
        this->speed = monster->GetSpeed();
        this->targetedSpeed = monster->GetTargetedSpeed();
        
    };
    
    ~ServerUpdateMonsterMessage() {};
    
protected:
    virtual void doGenerate() {
        (*p)<<monsterId<<angle<<position<<speed<<targetedSpeed;
    }
    
    
    virtual void doParse() {
        (*p)>>monsterId>>angle>>position>>speed>>targetedSpeed;
    }

};

}

#endif /* EIN_COMMON_SERVER_ADD_MONSTER_MESSAGE_H_ */
