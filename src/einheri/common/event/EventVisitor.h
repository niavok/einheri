/*
 * EventVisitor.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EVENTVISITOR_H_
#define EVENTVISITOR_H_

#include <einheri/utils/Visitor.h>
#include <einheri/common/event/EventAddPlayer.h>
#include <einheri/common/event/EventWindowClose.h>

namespace ein {

class EventVisitor
{
public:
    virtual void Visit(const EventAddPlayer&){}
    virtual void Visit(const EventWindowClose&){}
};

}  // namespace ehrCommon

#endif /* EVENTVISITOR_H_ */
