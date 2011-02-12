/*
 * EventWindowClose.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENTQUITGAME_H_
#define EIN_EVENTQUITGAME_H_

#include <einheri/common/Event.h>

namespace ein {

class EventVisitor;

class EventQuitGame: public Event {
public:
    EventQuitGame();
    virtual ~EventQuitGame();

    void accept(EventVisitor& visitor) const;
};

}

#endif /* EIN_EVENTQUITGAME_H_ */
