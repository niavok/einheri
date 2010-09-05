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

private:
    btBroadphaseInterface* broadphase;
    btDefaultCollisionConfiguration* collisionConfiguration;
    btCollisionDispatcher* dispatcher;
    btSequentialImpulseConstraintSolver* solver;
    btDiscreteDynamicsWorld* dynamicsWorld;
};

}

#endif /* EIN_ENGINEPHYSIC_H_ */
