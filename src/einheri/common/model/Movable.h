/*
 * Movable.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_MOVABLE_H_
#define EHR_COMMON_MOVABLE_H_

#include <einheri/common/Vect2.h>

namespace ein {

class Movable {
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

    EinValue GetAngle() const {
        return angle;
    }

private:
    EinId id;

    Vector position;
    Vector speed;
    EinValue angle;
};

}

#endif /* EHR_COMMON_MOVABLE_H_ */
