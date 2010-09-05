/*
 * EventWindowClose.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENTWINDOWCREATED_H_
#define EIN_EVENTWINDOWCREATED_H_

#include <einheri/common/Event.h>
#include <SFML/Graphics/RenderWindow.hpp>

namespace ein {

class EventVisitor;

class EventWindowCreated: public Event {
public:
    EventWindowCreated(sf::RenderWindow *window);
    virtual ~EventWindowCreated();

    void accept(EventVisitor& visitor) const;

    sf::RenderWindow *getWindow() const { return window; }

private:
    sf::RenderWindow *window;
};

}

#endif /* EIN_EVENTWINDOWCREATED_H_ */
