/*
 * EnginePhysic.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EnginePhysic.h"
#include <einheri/common/Event.h>
#include <einheri/common/event/EventVisitor.h>
#include "PhysicEntity.h"

namespace ein {

EnginePhysic::EnginePhysic(GameManager* manager) :
    FramerateEngine(manager) {
    UseSoftFrameRate(false);
    UseGameTime(true);
    initBulletEngine();
}

EnginePhysic::~EnginePhysic() {
    delete dynamicsWorld;
    delete solver;
    delete dispatcher;
    delete collisionConfiguration;
    delete broadphase;

}

void EnginePhysic::Apply(const Event& event) {
    class EnginePhysicVisitor: public EventVisitor {
    public:
        EnginePhysicVisitor(EnginePhysic* engine) :
            engine(engine) {
        }

        void Visit(const EventMonsterAdded& eventMonsterAdded) {
            engine->processEventMonsterAdded(eventMonsterAdded);
        }

        void Visit(const EventHeroAdded& eventHeroAdded) {
            engine->processEventHeroAdded(eventHeroAdded);
        }

    private:
        EnginePhysic* engine;
    };
    EnginePhysicVisitor visitor(this);
    event.accept(visitor);
}

void EnginePhysic::frame(EinValue frameTime) {
    importStates();
    dynamicsWorld->stepSimulation(frameTime, 10);
    exportStates();
}

void EnginePhysic::initBulletEngine() {
    broadphase = new btDbvtBroadphase();
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
    solver = new btSequentialImpulseConstraintSolver;
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);

    dynamicsWorld->setGravity(btVector3(0, 0, 0));

}

void EnginePhysic::processEventMonsterAdded(const EventMonsterAdded& eventMonsterAdded) {
    PhysicEntity *physicEntity = new PhysicEntity(eventMonsterAdded.GetMonster());
    physicEntities.push_back(physicEntity);

    dynamicsWorld->addRigidBody(physicEntity->GetRigidBody());
}

void EnginePhysic::processEventHeroAdded(const EventHeroAdded& eventHeroAdded) {
    PhysicEntity *physicEntity = new PhysicEntity(eventHeroAdded.GetHero());
    physicEntity->SetMass(1.5);
    physicEntities.push_back(physicEntity);

    dynamicsWorld->addRigidBody(physicEntity->GetRigidBody());
}

void EnginePhysic::importStates() {
    std::list<PhysicEntity *>::const_iterator it;
    for (it = physicEntities.begin(); it != physicEntities.end(); ++it) {
        PhysicEntity *physicEntity = *it;
        physicEntity->Import();
    }
}

void EnginePhysic::exportStates() {
    std::list<PhysicEntity *>::const_iterator it;
    for (it = physicEntities.begin(); it != physicEntities.end(); ++it) {
        PhysicEntity *physicEntity = *it;
        physicEntity->Export();
    }
}

}
