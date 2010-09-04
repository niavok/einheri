/*
 * ClientWorldModel.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef CLIENTWORLDMODEL_H_
#define CLIENTWORLDMODEL_H_

#include <SFML/System.hpp>
#include <map>
#include "Hero.h"
#include "Monster.h"
#include "Projectile.h"

namespace einheri {

class ClientWorldModel {
public:
    ClientWorldModel();
    virtual ~ClientWorldModel();

    void Lock();
    void Unlock();

    //void Copy(ClientWorldModel *sourceModel);

    void AddMonster(Monster *monster);
    void AddHero(Hero *hero);
    void AddProjectile(Projectile *projectile);

    const std::map<int, Monster *> &GetMonsters();

    const std::map<int, Hero *> &GetHeroes();
    const std::map<int, Projectile *> &GetProjectiles();

    sf::Mutex mutexMonsters;
    sf::Mutex mutexHeroes;
    sf::Mutex mutexProjectiles;


private:
    sf::Mutex lock;

    std::map<int, Hero *> heroes;
    std::map<int, Monster *> monsters;
    std::map<int, Projectile *> projectiles;


};

}

#endif /* CLIENTWORLDMODEL_H_ */
