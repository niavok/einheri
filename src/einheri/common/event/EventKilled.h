/*
 * EventAddPlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENT_KILLED_H_
#define EIN_EVENT_KILLED_H_

#include <einheri/common/Event.h>
#include <einheri/common/model/Hero.h>

namespace ein {

class EventVisitor;

class EventKilled : public Event{
public:
    EventKilled(Movable *victim);
    virtual ~EventKilled();

    void accept(EventVisitor& visitor)const;

    Movable *GetVictim() const { return victim; }

private:
    Movable *victim;
};

}

#endif /* EIN_EVENT_KILLED_H_ */
