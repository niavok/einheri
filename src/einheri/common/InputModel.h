/*
 * Model.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_INPUT_MODEL_H_
#define EIN_INPUT_MODEL_H_

#include <SFML/Window.hpp>
#include <einheri/common/Vect2.h>

namespace ein {

class InputModel {
public:
    InputModel();
    virtual ~InputModel();

    Vector GetMouse();
    bool GetKeyState(sf::Key::Code code);


    void SetInput(const sf::Input *input);


private:
    const sf::Input * input;


};

}

#endif /* EIN_INPUT_MODEL_H_ */
