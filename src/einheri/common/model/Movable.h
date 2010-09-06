/*
 * Movable.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_MOVABLE_H_
#define EHR_COMMON_MOVABLE_H_

#include <einheri/common/Vect2.h>
#include <einheri/utils/Visitor.h>

namespace ein {

class Movable : public einUtils::VisitableBase<Movable> {
public:
	EIN_DEFINE_VISITABLE()
public:
    Movable();
    virtual ~Movable();

    EinId GetId() const {
        return id;
    }

    Vector GetPosition() const {
        return position;
    }

    Vector GetSpeed() const {
        return speed;
    }

    Vector GetTargetedSpeed() const {
        return targetedSpeed;
    }

    EinValue GetAngle() const {
        return angle;
    }

    void SetPosition(Vector newPosition) {
        position = newPosition;
    }

    void SetSpeed(Vector newSpeed) {
        speed = newSpeed;
    }

    void SetTargetedSpeed(Vector newSpeed) {
        targetedSpeed = newSpeed;
    }

    void SetAngle(EinValue newAngle) {
        angle = newAngle;
    }

private:
    EinId id;

    Vector position;
    Vector speed;
    Vector targetedSpeed;
    EinValue angle;
};

}

#endif /* EHR_COMMON_MOVABLE_H_ */
