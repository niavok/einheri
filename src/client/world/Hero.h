/*
 * Heroes.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef HERO_H_
#define HERO_H_

#include "MapObject.h"

namespace einheri {

class Hero : public MapObject{
public:
    Hero();
    virtual ~Hero();

    double aimingAngle;
};



}  // namespace einheri


#endif /* HEROES_H_ */
