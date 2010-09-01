/*
 * Monster.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef SERVER_MONSTER_H_
#define SERVER_MONSTER_H_

namespace einheriServer {

class Monster {
public:
    Monster();
    virtual ~Monster();

    void GenerateId();

    int id;

    double positionX;
    double positionY;
    double speedX;
    double speedY;
    double angle;

};

}

#endif /* MONSTER_H_ */
