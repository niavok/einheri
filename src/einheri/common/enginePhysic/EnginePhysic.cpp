/*
 * EnginePhysic.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EnginePhysic.h"
#include <einheri/common/Event.h>

namespace ein {

EnginePhysic::EnginePhysic(GameManager* manager) :
    FramerateEngine(manager) {
    UseSoftFrameRate(false);
    initBulletEngine();
}

EnginePhysic::~EnginePhysic() {
    delete dynamicsWorld;
    delete solver;
    delete dispatcher;
    delete collisionConfiguration;
    delete broadphase;

}

void EnginePhysic::Apply(const Event& /*event*/) {
}

void EnginePhysic::frame(EinValue frameTime) {
    dynamicsWorld->stepSimulation(frameTime,10);
}

void EnginePhysic::initBulletEngine() {
    broadphase = new btDbvtBroadphase();
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
    solver = new btSequentialImpulseConstraintSolver;
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);

    dynamicsWorld->setGravity(btVector3(0, 0, 0));

}
}
