/*
 * EventAddPlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENT_MONSTER_ADDED_H_
#define EIN_EVENT_MONSTER_ADDED_H_

#include <einheri/common/Event.h>
#include <einheri/common/model/Monster.h>

namespace ein {

class EventVisitor;

class EventMonsterAdded : public Event{
public:
    EventMonsterAdded(Monster *monster);
    virtual ~EventMonsterAdded();

    void accept(EventVisitor& visitor)const;

    Monster *GetMonster() const { return monster; };

private:
    Monster *monster;
};

}

#endif /* EIN_EVENT_MONSTER_ADDED_H_ */
