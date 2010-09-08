/*
 * ProjectileController.cpp
 *
 *  Created on: 6 sept. 2010
 *      Author: fred
 */

#include "PlasmaBallController.h"
#include "einheri/common/model/PlasmaBall.h"
#include <einheri/common/event/EventKill.h>

namespace ein {

PlasmaBallController::PlasmaBallController(GameManager *manager) :
    ProjectileController(manager) {

}

PlasmaBallController::~PlasmaBallController() {

}

class CollisionPlasmaBallVisitor: public einUtils::Visitor<Movable, bool> {
public:
    CollisionPlasmaBallVisitor(PlasmaBallController* controller, Movable *collider) :
        controller(controller), collider(collider) {
        Visit(*this, einUtils::Seq<Movable, PlasmaBall>::Type(), CollisionInvoker());
    }
    virtual ~CollisionPlasmaBallVisitor() {
    }

protected:
    virtual bool Process(Movable& projectile) {
	std::cout<<"No PlasmaBall !"<< typeid(projectile).name()<<std::endl;
        return false;

    }

    virtual bool Process(PlasmaBall& ball) {
        std::cout<<" PlasmaBall !"<<std::endl;
        controller->Process(&ball, collider);

        return true;
    }

private:
    // Here you can change the name of the Visit method.
    typedef EIN_VISIT_INVOKER( Process ) CollisionInvoker;
    PlasmaBallController* controller;
    Movable* collider;
};

bool PlasmaBallController::processCollision(Projectile* projectile, Movable* collider) {

    std::cout<<" PlasmaBallController::processCollision 1"<<std::endl;

    CollisionPlasmaBallVisitor visitor(this, collider);

    bool result = visitor(*projectile);

    std::cout<<" PlasmaBallController::processCollision 2"<<result<<std::endl;

    return result;
    /*std::cout<<" PlasmaBallController::processCollision 1"<<std::endl;
    manager->AddEvent(new EventKill(projectile));
        manager->AddEvent(new EventKill(collider));
        std::cout<<" PlasmaBallController::processCollision 2"<<std::endl;
    return true;*/
}

void PlasmaBallController::Process(PlasmaBall* plasmaBall, Movable* collider) {
    if(plasmaBall->GetShooter() != collider) {
        manager->AddEvent(new EventKill(plasmaBall));
        manager->AddEvent(new EventKill(collider));
    }
}

}
