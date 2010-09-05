/*
 * EventVisitor.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EVENTVISITOR_H_
#define EVENTVISITOR_H_

#include <einheri/utils/Visitor.h>
#include <einheri/common/event/EventPrimaryActionUsed.h>
#include <einheri/common/event/EventWindowClose.h>
#include <einheri/common/event/EventWindowCreated.h>
#include <einheri/common/event/EventWindowResized.h>
#include <einheri/common/event/EventKeyPressed.h>
#include <einheri/common/event/EventKeyReleased.h>
#include <einheri/common/event/EventMouseButtonPressed.h>
#include <einheri/common/event/EventMouseButtonReleased.h>
#include <einheri/common/event/EventMonsterAdded.h>
#include <einheri/common/event/EventHeroAdded.h>
#include <einheri/common/event/EventProjectileAdded.h>

namespace ein {

class EventVisitor
{
public:
    virtual void Visit(const EventPrimaryActionUsed&){}
    virtual void Visit(const EventWindowClose&){}
    virtual void Visit(const EventWindowCreated&){}
    virtual void Visit(const EventWindowResized&){}
    virtual void Visit(const EventKeyPressed&){}
    virtual void Visit(const EventKeyReleased&){}
    virtual void Visit(const EventMouseButtonPressed&){}
    virtual void Visit(const EventMouseButtonReleased&){}
    virtual void Visit(const EventMonsterAdded&){}
    virtual void Visit(const EventHeroAdded&){}
    virtual void Visit(const EventProjectileAdded&){}

};

}  // namespace ehrCommon

#endif /* EVENTVISITOR_H_ */
