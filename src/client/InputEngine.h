/*
 * InputEngine.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef INPUTENGINE_H_
#define INPUTENGINE_H_

#include <SFML/Window.hpp>
#include "../common/MessageQueue.h"

namespace einheri {

class Application;

class InputEngine : private sf::Thread
{
public:
    InputEngine(Application *application);
    virtual ~InputEngine();

    void PushEvent(sf::Event event);
    void Start();
    void Stop();

    bool IsMoveLeft();
    bool IsMoveRight();
    bool IsMoveUp();
    bool IsMoveDown();

private:
    MessageQueue<sf::Event> eventQueue;

    Application *app;

    virtual void Run();
    bool running;
    const sf::Input *input;

};

}

#endif /* INPUTENGINE_H_ */
