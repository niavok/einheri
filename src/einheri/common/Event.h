/*
 * Event.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_EVENT_H_
#define EHR_COMMON_EVENT_H_

#include <einheri/utils/Visitor.h>

namespace ein {

class EventVisitor;

class Event {
public:
	Event() {
	}
	virtual ~Event() {
	}

	virtual void accept(EventVisitor &visitor) const =0;
};

}

#endif /* EHR_COMMON_EVENT_H_ */
