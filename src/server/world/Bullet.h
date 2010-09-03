/*
 * Heroes.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef SERVER_BULLET_H_
#define SERVER_BULLET_H_

#include "Projectile.h"


namespace einheriServer {

class Bullet : public Projectile{
public:
    Bullet();
    virtual ~Bullet();


};

}

#endif /* SERVER_BULLET_H_ */
