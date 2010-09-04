/*
 * Monster.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef MONSTER_H_
#define MONSTER_H_

#include "MapObject.h"

namespace einheri {

class Monster : public MapObject {
public:
    Monster();
    virtual ~Monster();

};

}

#endif /* MONSTER_H_ */
