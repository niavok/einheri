/*
 * EventAddPlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EVENTADDPLAYER_H_
#define EVENTADDPLAYER_H_

#include <einheri/common/Event.h>

namespace ein {

class EventVisitor;

class EventAddPlayer : public Event{
public:
    EventAddPlayer();
    virtual ~EventAddPlayer();

    void accept(EventVisitor& visitor)const;
};

}

#endif /* EVENTADDPLAYER_H_ */
