/*
 * Monster.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef MONSTER_H_
#define MONSTER_H_

namespace einheri {

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
