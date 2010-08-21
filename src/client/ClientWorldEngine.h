/*
 * ClientWorldEngine.h
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */

#ifndef CLIENTWORLDENGINE_H_
#define CLIENTWORLDENGINE_H_

#include <SFML/Window.hpp>
#include "ClientWorldModel.h"

class ClientWorldEngine : private sf::Thread {
public:
    ClientWorldEngine();
    virtual ~ClientWorldEngine();

    void SwapModel();

    void Start();
    void Stop();


private:

    Clock clock;
    virtual void Run();
    bool running;


    ClientWorldModel *editedModel;
    ClientWorldModel *viewedModel;


    ClientWorldModel model1;
    ClientWorldModel model2;

};

#endif /* CLIENTWORLDENGINE_H_ */
