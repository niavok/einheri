#ifndef EIN_EVENT_MONSTER_UPDATED_H_
#define EIN_EVENT_MONSTER_UPDATED_H_

#include <einheri/common/Event.h>
#include <einheri/common/model/Monster.h>

namespace ein {

class EventVisitor;

class EventMonsterUpdated : public Event{
public:
    EventMonsterUpdated(Monster *monster);
    virtual ~EventMonsterUpdated();

    void accept(EventVisitor& visitor)const;

    Monster *GetMonster() const { return monster; };

private:
    Monster *monster;
};

}

#endif /* EIN_EVENT_MONSTER_UPDATED_H_ */
