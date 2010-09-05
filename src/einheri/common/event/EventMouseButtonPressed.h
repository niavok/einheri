/*
 * EventWindowClose.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENTMOUSEBUTTONPRESSED_H_
#define EIN_EVENTMOUSEBUTTONPRESSED_H_

#include <einheri/common/Event.h>
#include <einheri/common/Vect2.h>
#include <SFML/Window.hpp>

namespace ein {

class EventVisitor;

class EventMouseButtonPressed: public Event {
public:
    EventMouseButtonPressed(sf::Mouse::Button button);
    virtual ~EventMouseButtonPressed();

    void accept(EventVisitor& visitor) const;

    sf::Mouse::Button getMouseButton() const { return button; }

private:
    sf::Mouse::Button button;
};

}

#endif /* EIN_EVENTMOUSEBUTTONPRESSED_H_ */
