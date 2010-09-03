/*
 * ClientWorldModel.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef SERVER_WORLDMODEL_H_
#define SERVER_WORLDMODEL_H_

#include <vector>
#include <SFML/System.hpp>
#include "Hero.h"
#include "Monster.h"
#include "Projectile.h"
#include "Map.h"
#include <map>

namespace einheriServer {

class WorldModel {
public:
    WorldModel();
    virtual ~WorldModel();

    void Lock();
    void Unlock();

    Map map;
    std::map<int, Hero *> heroes;
    std::map<int, Monster *> monsters;
    std::map<int, Projectile *> projectiles;
private:
    sf::Mutex lock;

};

}

#endif /* WORLDMODEL_H_ */
