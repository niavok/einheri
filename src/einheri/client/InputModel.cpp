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

}

InputModel::~InputModel() {

}

void InputModel::SetInput(const sf::Input * input) {
    this->input = input;
}



Vector InputModel::GetMouse() {
    if(input) {
        return Vector(input->GetMouseX(),input->GetMouseY());
    } else {
        return Vector(0.,0.);
    }
}

bool InputModel::GetKeyState(sf::Key::Code code) {
    if(input) {
            return input->IsKeyDown(code);
        } else {
            return false;
        }
}



}
