/*
 * MonsterAI.h
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#ifndef EIN_PHYSICENTITY_H_
#define EIN_PHYSICENTITY_H_
#include <einheri/common/model/Movable.h>
#include <einheri/common/enginePhysic/KineticMotionState.h>
#include <btBulletDynamicsCommon.h>

namespace ein {

class PhysicEntity {
public:
    PhysicEntity(Movable *moveable);
    virtual ~PhysicEntity();

    btRigidBody* GetRigidBody() { return rigidBody; }

    void SetMass(EinValue mass);

    void Import();
    void Export();

    Movable *GetMovable() {return movable; }

protected:
    Movable *movable;
    btRigidBody* rigidBody;
    btCollisionShape* sphereShape;
    KinematicMotionState* motionState;
};

}

#endif /* EIN_PHYSICENTITY_H_ */
