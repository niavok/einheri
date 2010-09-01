/*
 * Heroes.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef SERVER_HERO_H_
#define SERVER_HERO_H_

namespace einheriServer {

class Hero {
public:
    Hero();
    virtual ~Hero();

    double positionX;
    double positionY;
    double speedX;
    double speedY;
    double angle;
};

}

#endif /* HERO_H_ */
