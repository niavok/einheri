/*
 * Projectile.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_PLASMA_BALL_H_
#define EIN_PLASMA_BALL_H_
#include <einheri/common/model/Projectile.h>

namespace ein {

class PlasmaBall: public Projectile {
public:
    EIN_DEFINE_VISITABLE()
public:
    PlasmaBall();
    virtual ~PlasmaBall();
};

}

#endif /* EIN_PLASMA_BALL_H_ */
