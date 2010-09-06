/*
 * EventAddPlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EVENT_OBJECT_COLLISION_H_
#define EIN_EVENT_OBJECT_COLLISION_H_

#include <einheri/common/Event.h>
#include <einheri/common/model/Hero.h>

namespace ein {

class EventVisitor;

class EventObjectCollision : public Event{
public:
    EventObjectCollision(Movable *object1, Movable *object2);
    virtual ~EventObjectCollision();

    void accept(EventVisitor& visitor)const;

    Movable *GetObject1() const { return object1; }
    Movable *GetObject2() const { return object2; }

private:
    Movable *object1;
    Movable *object2;
};

}

#endif /* EIN_EVENT_OBJECT_COLLISION_H_ */
