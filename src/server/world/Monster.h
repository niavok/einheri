/*
 * Monster.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef SERVER_MONSTER_H_
#define SERVER_MONSTER_H_

#include "MapObject.h"

namespace einheriServer {

class Monster : public MapObject {
public:
    Monster();
    virtual ~Monster();

};

}

#endif /* MONSTER_H_ */
