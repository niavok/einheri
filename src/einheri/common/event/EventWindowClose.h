/*
 * EventWindowClose.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENTWINDOWCLOSE_H_
#define EIN_EVENTWINDOWCLOSE_H_

#include <einheri/common/Event.h>

namespace ein {

class EventVisitor;

class EventWindowClose: public Event {
public:
    EventWindowClose();
    virtual ~EventWindowClose();

    void accept(EventVisitor& visitor) const;
};

}

#endif /* EIN_EVENTWINDOWCLOSE_H_ */
