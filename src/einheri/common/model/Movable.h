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

    EinId getId() const {
        return id;
    }

    Vector getPosition() const {
        return position;
    }

    Vector getSpeed() const {
        return speed;
    }

    EinValue getAngle() const {
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
