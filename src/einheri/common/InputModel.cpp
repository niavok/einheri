/*
 * Model.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "InputModel.h"

namespace ein {

InputModel::InputModel() {
    input = NULL;
    windowSize = Vector(0.,0.);
}

InputModel::~InputModel() {

}

void InputModel::SetInput(const sf::Input * input) {
    this->input = input;
}

void InputModel::SetWindowSize(Vector newSize) {
    windowSize = newSize;
}

Vector InputModel::GetMouse() {
    if(input) {
        return Vector(input->GetMouseX(),input->GetMouseY());
    } else {
        return Vector(0.,0.);
    }
}

Vector InputModel::GetWindowSize() const{
    return windowSize;
}

}
