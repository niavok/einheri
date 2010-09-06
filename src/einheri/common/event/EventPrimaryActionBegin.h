/*
 * EventAddPlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENT_PRIMARY_ACTION_BEGIN_H_
#define EIN_EVENT_PRIMARY_ACTION_BEGIN_H_

#include <einheri/common/Event.h>
#include <einheri/common/Player.h>

namespace ein {

class EventVisitor;

class EventPrimaryActionBegin : public Event{
public:
    EventPrimaryActionBegin(Player *player);
    virtual ~EventPrimaryActionBegin();

    void accept(EventVisitor& visitor)const;

    Player *GetPlayer() const { return player; }

private:
    Player * player;
};

}

#endif /* EIN_EVENT_PRIMARY_ACTION_BEGIN_H_ */
