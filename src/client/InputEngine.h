/*
 * InputEngine.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef INPUTENGINE_H_
#define INPUTENGINE_H_

#include <SFML/Window.hpp>
#include "MessageQueue.h"

namespace einheri {

class InputEngine : private sf::Thread
{
public:
    InputEngine();
    virtual ~InputEngine();

    void PushEvent(sf::Event event);
    void Start();
    void Stop();

private:
    MessageQueue<sf::Event> eventQueue;

    virtual void Run();
    bool running;

};

}

#endif /* INPUTENGINE_H_ */
