/*
 * EventAddPlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENT_HERO_ADDED_H_
#define EIN_EVENT_HERO_ADDED_H_

#include <einheri/common/Event.h>
#include <einheri/common/model/Hero.h>

namespace ein {

class EventVisitor;

class EventHeroAdded : public Event{
public:
    EventHeroAdded(Hero *hero);
    virtual ~EventHeroAdded();

    void accept(EventVisitor& visitor)const;

    Hero *GetHero() const { return hero; };

private:
    Hero *hero;
};

}

#endif /* EIN_EVENT_HERO_ADDED_H_ */
