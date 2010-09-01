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
    std::vector<Hero *> heroes;
    std::vector<Monster *> monsters;
    std::map<int, Hero *> heroesMap;
    std::map<int, Monster *> monstersMap;

private:
    sf::Mutex lock;

};

}

#endif /* WORLDMODEL_H_ */
