/*
 * Heroes.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef HERO_H_
#define HERO_H_

namespace einheri {

class Hero {
public:
    Hero();
    virtual ~Hero();

    int id;

    double positionX;
    double positionY;
    double angle;
};



}  // namespace einheri


#endif /* HEROES_H_ */