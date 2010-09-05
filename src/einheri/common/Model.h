/*
 * Model.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_MODEL_H_
#define EHR_COMMON_MODEL_H_

#include <list>
#include <einheri/common/model/Building.h>
#include <einheri/common/model/Hero.h>
#include <einheri/common/model/Monster.h>
#include <einheri/common/model/Projectile.h>

namespace ein {

class Model {
public:
    Model();
    virtual ~Model();

    const std::list<Building*>& GetBuildings() const {
        return buildings;
    }

    const std::list<Hero*> &GetHeroes() const {
        return heroes;
    }

    const std::list<Monster*> &GetMonsters() const {
        return monsters;
    }

    const std::list<Projectile*> &GetProjectiles() const {
        return projectiles;
    }

private:
    std::list<Projectile *> projectiles;
    std::list<Hero *> heroes;
    std::list<Monster *> monsters;
    std::list<Building *> buildings;

};

}

#endif /* EHR_COMMON_MODEL_H_ */
