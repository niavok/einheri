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

class CollisionVisitor: public einUtils::Visitor<const Movable, bool> {
public:
    CollisionVisitor(PlasmaBallController* controller, Movable *collider) :
        controller(controller), collider(collider) {
        Visit(*this, einUtils::Seq<Movable, PlasmaBall>::Type(), CollisionInvoker());
    }
    virtual ~CollisionVisitor() {
    }

protected:
    virtual bool Process(const Movable& ) {
        return false;
    }

    virtual bool Process(PlasmaBall& ball) {
        controller->Process(&ball, collider);

        return true;
    }

private:
    // Here you can change the name of the Visit method.
    typedef EIN_VISIT_INVOKER( Process ) CollisionInvoker;
    PlasmaBallController* controller;
    Movable* collider;
};

bool PlasmaBallController::processCollision(const Projectile* projectile, Movable* collider) {

    CollisionVisitor visitor(this, collider);

    bool result = visitor(*projectile);

    std::cout<<" PlasmaBallController::processCollision "<<result<<std::endl;

    return result;
}

void PlasmaBallController::Process(PlasmaBall* plasmaBall, Movable* collider) {
    manager->AddEvent(new EventKill(plasmaBall));
    manager->AddEvent(new EventKill(collider));
}

}
