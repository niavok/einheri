/*
 * Heroes.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef HERO_H_
#define HERO_H_

class Hero {
public:
    Hero();
    virtual ~Hero();

    double positionX;
    double positionY;
    double angle;
};

#endif /* HEROES_H_ */
