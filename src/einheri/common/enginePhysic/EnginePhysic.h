/*
 * EnginePhysic.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_ENGINEPHYSIC_H_
#define EIN_ENGINEPHYSIC_H_

#include <einheri/common/FramerateEngine.h>
#include <btBulletDynamicsCommon.h>
#include <einheri/common/event/EventMonsterAdded.h>
#include <list>
#include "PhysicEntity.h"
#include "einheri/common/event/EventHeroAdded.h"
#include "einheri/common/event/EventProjectileAdded.h"

namespace ein {

class Event;

class EnginePhysic : public FramerateEngine {
public:
    EnginePhysic(GameManager* manager);
    virtual ~EnginePhysic();

    void Apply(const Event& event);
    void frame(EinValue frameTime);

private:
    void initBulletEngine();
    void processEventMonsterAdded(const EventMonsterAdded& eventMonsterAdded);
    void processEventHeroAdded(const EventHeroAdded& eventHeroAdded);
    void processEventProjectileAdded(const EventProjectileAdded& eventProjectileAdded);

    void importStates();
    void exportStates();

private:
    btBroadphaseInterface* broadphase;
    btDefaultCollisionConfiguration* collisionConfiguration;
    btCollisionDispatcher* dispatcher;
    btSequentialImpulseConstraintSolver* solver;
    btDiscreteDynamicsWorld* dynamicsWorld;

    std::list<PhysicEntity *> physicEntities;
};

}

#endif /* EIN_ENGINEPHYSIC_H_ */
