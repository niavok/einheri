/*
 * Projectile.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_MONSTER_H_
#define EHR_COMMON_MONSTER_H_

#include "Movable.h"

namespace ein {

class Monster: public ein::Movable {
public:
    Monster();
    virtual ~Monster();
};

}

#endif /* EHR_COMMON_MONSTER_H_ */
