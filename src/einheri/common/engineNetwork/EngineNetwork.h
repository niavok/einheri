/*
 * EngineNetwork.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINENETWORK_H_
#define EHR_COMMON_ENGINENETWORK_H_

#include <einheri/common/Engine.h>

namespace ein {

class Event;

class EngineNetwork : public Engine{
public:
    EngineNetwork(GameManager* manager);
    virtual ~EngineNetwork();

    void apply(const Event& event);
    void frame();

};

}

#endif /* EHR_COMMON_ENGINENETWORK_H_ */
