/*
 * EventWindowClose.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENTWINDOWRESIZED_H_
#define EIN_EVENTWINDOWRESIZED_H_

#include <einheri/common/Event.h>
#include <einheri/common/Vect2.h>

namespace ein {

class EventVisitor;

class EventWindowResized: public Event {
public:
    EventWindowResized(Vector size);
    virtual ~EventWindowResized();

    void accept(EventVisitor& visitor) const;

    Vector getSize() const { return size; }

private:
    Vector size;
};

}

#endif /* EIN_EVENTWINDOWRESIZED_H_ */
