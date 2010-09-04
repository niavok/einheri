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
#include "world/ClientWorldEngine.h"
#include "GameEngine.h"
#include <SFML/Graphics.hpp>

namespace einheri {

class Application {
public:
    Application();
    virtual ~Application();

    einheri::ClientWorldEngine clientWorldEngine;
    einheri::GameEngine gameEngine;
    einheri::GraphicEngine graphicEngine;
    einheri::InputEngine inputEngine;
    einheri::NetworkEngine networkEngine;


    void Run();

    sf::RenderWindow *app;
};

}

#endif /* APPLICATION_H_ */
