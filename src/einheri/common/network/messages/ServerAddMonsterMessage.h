#ifndef EIN_COMMON_SERVER_ADD_MONSTER_MESSAGE_H_
#define EIN_COMMON_SERVER_ADD_MONSTER_MESSAGE_H_
#include "NetworkMessage.h"
#include <einheri/common/model/Monster.h>

namespace ein {


class ServerAddMonsterMessage: public  NetworkMessage{
public:
    //Structure
    int monsterId;    
    std::string monsterName;
    EinValue angle;
    Vector position;
    EinValue radius;
    Vector speed;
    Vector targetedSpeed;

    ServerAddMonsterMessage():NetworkMessage(NetworkMessage::SERVER_ADD_MONSTER) {};
    
    ServerAddMonsterMessage(Monster *monster):NetworkMessage(NetworkMessage::SERVER_ADD_MONSTER) {
        this->monsterId = monster->GetId();
        this->monsterName = monster->GetName();
        this->angle =  monster->GetAngle();
        this->position = monster->GetPosition();
        this->radius = monster->GetRadius();
        this->speed = monster->GetSpeed();
        this->targetedSpeed = monster->GetTargetedSpeed();
        
    };
    
    ~ServerAddMonsterMessage() {};
    
protected:
    virtual void doGenerate() {
        (*p)<<monsterId<<monsterName<<angle<<position<<radius<<speed<<targetedSpeed;
    }
    
    
    virtual void doParse() {
        (*p)>>monsterId>>monsterName>>angle>>position>>radius>>speed>>targetedSpeed;
    }

};

}

#endif /* EIN_COMMON_SERVER_ADD_MONSTER_MESSAGE_H_ */
