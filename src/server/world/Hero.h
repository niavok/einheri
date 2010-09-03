/*
 * Heroes.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef SERVER_HERO_H_
#define SERVER_HERO_H_

#include "MapObject.h"


namespace einheriServer {

class Player;

class Hero : public MapObject{
public:
    Hero();
    virtual ~Hero();

    double aimingAngle;

    bool playerMove;
    double playerAngle;
    double playerSpeed;
    double playerAimingAngle;

    Player * parentPlayer;

};

}

#endif /* HERO_H_ */
