/*
 * EventWindowClose.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENTMOUSEBUTTONRELEASED_H_
#define EIN_EVENTMOUSEBUTTONRELEASED_H_

#include <einheri/common/Event.h>
#include <einheri/common/Vect2.h>
#include <SFML/Window.hpp>

namespace ein {

class EventVisitor;

class EventMouseButtonReleased: public Event {
public:
    EventMouseButtonReleased(sf::Mouse::Button button);
        virtual ~EventMouseButtonReleased();

        void accept(EventVisitor& visitor) const;

        sf::Mouse::Button getMouseButton() const { return button; }

    private:
        sf::Mouse::Button button;
};

}

#endif /* EIN_EVENTMOUSEBUTTONRELEASED_H_ */
