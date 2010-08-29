/*
 * Application.h
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "NetworkEngine.h"
#include "NetworkNotifier.h"
#include "WorldEngine.h"
#include "GameEngine.h"


namespace einheri {

class Application {
public:
    Application();
    virtual ~Application();

    NetworkEngine networkEngine;
    GameEngine gameEngine;
    NetworkNotifier networkNotifier;
    WorldEngine worldEngine;


    void Run();

};

}

#endif /* APPLICATION_H_ */
