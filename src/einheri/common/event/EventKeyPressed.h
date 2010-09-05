/*
 * EventWindowClose.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENTKEYPRESSED_H_
#define EIN_EVENTKEYPRESSED_H_

#include <einheri/common/Event.h>
#include <einheri/common/Vect2.h>
#include <SFML/Window.hpp>

namespace ein {

class EventVisitor;

class EventKeyPressed: public Event {
public:
    EventKeyPressed(sf::Key::Code keyCode);
    virtual ~EventKeyPressed();

    void accept(EventVisitor& visitor) const;

    sf::Key::Code getKeyCode() const { return keyCode; }

private:
    sf::Key::Code keyCode;
};

}

#endif /* EIN_EVENTKEYPRESSED_H_ */
