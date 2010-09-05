#ifndef EIN_KINETIC_MOTIONSTATE_H_
#define EIN_KINETIC_MOTIONSTATE_H_
#include <btBulletDynamicsCommon.h>

#include <iostream>

namespace ein {

class KinematicMotionState : public btMotionState {
public:
        KinematicMotionState(const btTransform &initialpos, Movable *movable) {
            this->movable = movable;
            position = initialpos;
        }

        virtual ~KinematicMotionState() {
        }

        virtual void getWorldTransform(btTransform &worldTrans) const {
            worldTrans = position;
        }


        virtual void setWorldTransform(const btTransform &worldTrans) {
            movable->SetPosition(Vector(worldTrans.getOrigin().x(),worldTrans.getOrigin().y()));
        }


protected:
    btTransform position;
    Movable *movable;
};

}

#endif /* EIN_KINETIC_MOTIONSTATE_H_ */
