/*
 * EventAddPlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENT_PRIMARY_ACTION_USED_H_
#define EIN_EVENT_PRIMARY_ACTION_USED_H_

#include <einheri/common/Event.h>
#include <einheri/common/Player.h>

namespace ein {

class EventVisitor;

class EventPrimaryActionUsed : public Event{
public:
    EventPrimaryActionUsed(Player *player);
    virtual ~EventPrimaryActionUsed();

    void accept(EventVisitor& visitor)const;

    Player *GetPlayer() const { return player; }

private:
    Player * player;
};

}

#endif /* EIN_EVENT_PRIMARY_ACTION_USED_H_ */
