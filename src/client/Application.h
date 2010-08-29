/*
 * Application.h
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "GraphicEngine.h"
#include "InputEngine.h"
#include "NetworkEngine.h"
#include "ClientWorldEngine.h"
#include "GameEngine.h"
#include <SFML/Graphics.hpp>

namespace einheri {

class Application {
public:
    Application();
    virtual ~Application();

    einheri::GraphicEngine graphicEngine;
    einheri::InputEngine inputEngine;
    einheri::ClientWorldEngine clientWorldEngine;
    einheri::NetworkEngine networkEngine;
    einheri::GameEngine gameEngine;


    void Run();

    sf::RenderWindow *app;
};

}

#endif /* APPLICATION_H_ */
