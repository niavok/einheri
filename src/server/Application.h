/*
 * Application.h
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */

#ifndef SERVER_APPLICATION_H_
#define SERVER_APPLICATION_H_

#include "NetworkEngine.h"
#include "NetworkNotifier.h"
#include "world/WorldEngine.h"
#include "GameEngine.h"


namespace einheriServer {

class Application {
public:
    Application();
    virtual ~Application();

    GameEngine gameEngine;
    NetworkEngine networkEngine;
    NetworkNotifier networkNotifier;
    WorldEngine worldEngine;


    void Run();

};

}

#endif /* APPLICATION_H_ */
