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
#include <einheri/utils/Log.h>
#include <einheri/common/GameManager.h>
#include "einheri/common/event/EventObjectCollision.h"

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

        void Visit(const EventProjectileAdded& eventProjectileAdded) {
            engine->processEventProjectileAdded(eventProjectileAdded);
        }

        void Visit(const EventKill& event) {
                engine->processEventKill(event);
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

    processCollision();

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

void EnginePhysic::processEventProjectileAdded(const EventProjectileAdded& eventProjectileAdded) {
    PhysicEntity *physicEntity = new PhysicEntity(eventProjectileAdded.GetProjectile());
    physicEntity->SetMass(1000.1);
    physicEntities.push_back(physicEntity);

    dynamicsWorld->addRigidBody(physicEntity->GetRigidBody());
}

void EnginePhysic::processEventKill(const EventKill& event) {
    std::list<PhysicEntity *>::const_iterator it;
    for (it = physicEntities.begin(); it != physicEntities.end(); ++it) {
        PhysicEntity *physicEntity = *it;
        if(physicEntity->GetMovable() == event.GetVictim()) {
            std::cout<<"EnginePhysic::processEventKill "<<physicEntity<<std::endl;
            dynamicsWorld->removeRigidBody(physicEntity->GetRigidBody());
            physicEntities.remove(physicEntity);
            break;
        }
    }
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

void EnginePhysic::processCollision() {
    int numManifolds = dynamicsWorld->getDispatcher()->getNumManifolds();
        for (int i=0;i<numManifolds;i++)
        {
            btPersistentManifold* contactManifold =  dynamicsWorld->getDispatcher()->getManifoldByIndexInternal(i);
            btCollisionObject* obA = static_cast<btCollisionObject*>(contactManifold->getBody0());
            btCollisionObject* obB = static_cast<btCollisionObject*>(contactManifold->getBody1());

            PhysicEntity *objectA = (PhysicEntity*) obA->getUserPointer();
            PhysicEntity *objectB = (PhysicEntity*) obB->getUserPointer();

            if(objectA->GetMovable()->IsNeedReportingCollision() || objectB->GetMovable()->IsNeedReportingCollision()) {
                //std::cout<<"EnginePhysic::processCollision"<<std::endl;
                manager->AddEvent(new EventObjectCollision(objectA->GetMovable(), objectB->GetMovable()));
            }


            /*int numContacts = contactManifold->getNumContacts();
            for (int j=0;j<numContacts;j++)
            {
                btManifoldPoint& pt = contactManifold->getContactPoint(j);
                if (pt.getDistance()<0.f)
                {
                    const btVector3& ptA = pt.getPositionWorldOnA();
                    const btVector3& ptB = pt.getPositionWorldOnB();
                    const btVector3& normalOnB = pt.m_normalWorldOnB;
                }
            }*/
        }

}

}
