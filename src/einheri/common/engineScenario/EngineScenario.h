/*
 * EngineGame.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINESCENARIO_H_
#define EHR_COMMON_ENGINESCENARIO_H_

#include <einheri/common/Engine.h>

namespace ein {

class Event;

class EngineScenario : public Engine{
public:
    EngineScenario(GameManager* manager);
    virtual ~EngineScenario();

    void Apply(const Event& event);
    void Frame();

};

}

#endif /* EHR_COMMON_ENGINESCENARIO_H_ */
