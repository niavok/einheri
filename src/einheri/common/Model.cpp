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
    // TODO Auto-generated destructor stub
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
    std::cout<<"Model::Remove "<<movable<<std::endl;
    RemoveVisitor visitor(this);
    visitor(*movable);
    std::cout<<"Model::Remove fuite mémoire"<<movable<<std::endl;
}

void Model::RemoveMonster(Monster *monster) {
    monsters.remove(monster);
    //delete monster;
}
void Model::RemoveHero(Hero *hero) {
    heroes.remove(hero);
    //delete hero;
}
void Model::RemoveProjectile(Projectile *projectile) {
    projectiles.remove(projectile);
    //delete projectile;
}
void Model::RemoveBuilding(Building *building) {
    buildings.remove(building);
    //delete building;
}

}
