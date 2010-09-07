/*
 * EventAddPlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENT_KILL_H_
#define EIN_EVENT_KILL_H_

#include <einheri/common/Event.h>
#include <einheri/common/model/Hero.h>

namespace ein {

class EventVisitor;

class EventKill : public Event{
public:
    EventKill(Movable *victim);
    virtual ~EventKill();

    void accept(EventVisitor& visitor)const;

    Movable *GetVictim() const { return victim; }

private:
    Movable *victim;
};

}

#endif /* EIN_EVENT_KILL_H_ */
