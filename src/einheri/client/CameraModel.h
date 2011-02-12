/*
 * Model.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_CAMERA_MODEL_H_
#define EIN_CAMERA_MODEL_H_

#include <einheri/common/Vect2.h>

namespace ein {

class CameraModel {
public:
    CameraModel();
    virtual ~CameraModel();

    EinValue GetDistance() const { return distance; }
    Vector GetPosition() const { return position; }

    void SetDistance(EinValue newDistance) {distance = newDistance; }
    void SetPosition(Vector newPosition) {position = newPosition; }

    void SetWindowSize(Vector newSize);
    Vector GetWindowSize() const;

    Vector Pick(Vector point);

private:
    EinValue distance;
    Vector position;
    Vector windowSize;

};

}

#endif /* EIN_CAMERA_MODEL_H_ */
