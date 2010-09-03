/*
 * Projectile
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef SERVER_PROJECTILE_H_
#define SERVER_PROJECTILE_H_

#include "MapObject.h"
#include "../../common/EinheriProtocol.h"

namespace einheriServer {

class Hero;

class Projectile : public MapObject{
public:
    Projectile();
    virtual ~Projectile();

    Hero * shooter;
    einheri::EinheriProtocol::ProjectileType projectileType;

};

}

#endif /* SERVER_PROJECTILE_H_ */
