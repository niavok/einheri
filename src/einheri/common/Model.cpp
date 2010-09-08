/*
 * Model.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "Model.h"
#include <einheri/common/model/PlasmaBall.h>

namespace ein {

Model::Model() {
    // TODO Auto-generated constructor stub

}

Model::~Model() {
    while (!monsters.empty()) {
        Movable *movable = monsters.front();
        delete movable;
        monsters.pop_front();
    }

    while (!heroes.empty()) {
        Movable *movable = heroes.front();
        delete movable;
        heroes.pop_front();
    }

    while (!buildings.empty()) {
        Movable *movable = buildings.front();
        delete movable;
        buildings.pop_front();
    }

    while (!projectiles.empty()) {
        Movable *movable = projectiles.front();
        delete movable;
        projectiles.pop_front();
    }
}

class RemoveVisitor: public einUtils::Visitor<const Movable> {
public:
    RemoveVisitor(Model* model) :
        model(model) {
        Visit(*this, einUtils::Seq<Hero, Projectile, Monster, Building, PlasmaBall>::Type(), CollisionInvoker());
    }
    virtual ~RemoveVisitor() {
    }

protected:
    virtual void Remove(const Movable&) {

    }

    virtual void Remove(const Building& building) {
        model->RemoveBuilding(const_cast<Building*> (&building));
    }

    virtual void Remove(const Monster& monster) {
        model->RemoveMonster(const_cast<Monster*> (&monster));
    }

    virtual void Remove(const Hero& hero) {
        model->RemoveHero(const_cast<Hero*> (&hero));
    }
    virtual void Remove(const Projectile& projectile) {
        model->RemoveProjectile(const_cast<Projectile*> (&projectile));

    }

private:
    // Here you can change the name of the Visit method.
    typedef EIN_VISIT_INVOKER( Remove ) CollisionInvoker;
    Model* model;
};

void Model::Remove(Movable *movable) {
    std::cout<<"Model::Remove "<<movable->GetName()<<" "<<movable<<std::endl;
    RemoveVisitor visitor(this);
    visitor(*movable);
}

void Model::RemoveMonster(Monster *monster) {
    std::cout<<"Model::RemoveMonster 1 "<<monsters.size()<<std::endl;
    monsters.remove(monster);
    std::cout<<"Model::RemoveMonster 2 "<<monsters.size()<<std::endl;
    std::cout<<"Model::RemoveMonster monster "<<monster<<std::endl;
    delete monster;
}
void Model::RemoveHero(Hero *hero) {
    heroes.remove(hero);
    delete hero;
}
void Model::RemoveProjectile(Projectile *projectile) {
    std::cout<<"Model::RemoveProjectile 1 "<<projectiles.size()<<std::endl;
    projectiles.remove(projectile);
    std::cout<<"Model::RemoveProjectile 2 "<<projectiles.size()<<std::endl;
    delete projectile;
}
void Model::RemoveBuilding(Building *building) {
    buildings.remove(building);
    delete building;
}

}
