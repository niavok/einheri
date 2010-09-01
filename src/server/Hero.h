/*
 * Heroes.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef SERVER_HERO_H_
#define SERVER_HERO_H_

namespace einheriServer {

class Player;

class Hero {
public:
    Hero();
    virtual ~Hero();

    int id;

    double positionX;
    double positionY;
    double speedX;
    double speedY;
    double angle;

    bool playerMove;
    double playerAngle;
    double playerSpeed;

    Player * parentPlayer;

    void GenerateId();
};

}

#endif /* HERO_H_ */
