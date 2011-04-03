/*
 * Model.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_MODEL_H_
#define EHR_COMMON_MODEL_H_

#include <list>
#include <map>
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

    const std::list<Hero*>& GetHeroes() const {
        return heroes;
    }

    const std::list<Monster*>& GetMonsters() const {
        return monsters;
    }
    
    Monster* GetMonster(EinId id) const {
        return monsterIdCache.at(id);
    }

    const std::list<Projectile*>& GetProjectiles() const {
        return projectiles;
    }

    void AddMonster(Monster *monster) {
        monsters.push_back(monster);
        monsterIdCache.insert(std::pair<EinId, Monster*>(monster->GetId(), monster));
    }

    void AddHero(Hero *hero) {
        heroes.push_back(hero);
    }

    void AddProjectile(Projectile *projectile) {
        projectiles.push_back(projectile);
    }

    void AddBuilding(Building *building) {
        buildings.push_back(building);
    }

    void Remove(Movable *movable);

    void RemoveMonster(Monster *monster);
    void RemoveHero(Hero *hero);
    void RemoveProjectile(Projectile *projectile);
    void RemoveBuilding(Building *building);


private:
    std::list<Projectile *> projectiles;
    std::list<Hero *> heroes;
    std::list<Monster *> monsters;
    std::map<EinId, Monster *> monsterIdCache;
    std::list<Building *> buildings;


};

}

#endif /* EHR_COMMON_MODEL_H_ */
