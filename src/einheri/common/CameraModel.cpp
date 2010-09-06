/*
 * Model.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "CameraModel.h"

namespace ein {

CameraModel::CameraModel() {
    distance = 30;
    position = Vector(0.,0.);
    windowSize = Vector(0.,0.);

}

CameraModel::~CameraModel() {

}

void CameraModel::SetWindowSize(Vector newSize) {
    windowSize = newSize;
}

Vector CameraModel::Pick(Vector point) {

    double h = 1;

    if (windowSize.getY() != 0) {
        h =  windowSize.getX() /  windowSize.getY();
    }

    double pickX = (h*distance) * ( point.getX() /  windowSize.getX() - 1./2.) + position.getX();
    double pickY = distance * ( (windowSize.getY() - point.getY()) /  windowSize.getY() - 1./2.) + position.getY();


    return Vector(pickX, pickY);
}

Vector CameraModel::GetWindowSize() const{
    return windowSize;
}


}
