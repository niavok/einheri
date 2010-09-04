/*
 * Projectile
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef CLIENT_PROJECTILE_H_
#define CLIENT_PROJECTILE_H_

#include "MapObject.h"
#include "../../common/EinheriProtocol.h"

namespace einheri {

class Hero;

class Projectile : public MapObject{
public:
    Projectile();
    virtual ~Projectile();

    Hero * shooter;
    einheri::EinheriProtocol::ProjectileType projectileType;

};

}

#endif /* CLIENT_PROJECTILE_H_ */
