/*
 * Projectile.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_PROJECTILE_H_
#define EHR_COMMON_PROJECTILE_H_

#include "Movable.h"

namespace ein {

class Projectile: public ein::Movable {
public:
    Projectile();
    virtual ~Projectile();
};

}

#endif /* EHR_COMMON_PROJECTILE_H_ */
