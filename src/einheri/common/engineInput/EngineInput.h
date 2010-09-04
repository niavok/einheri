/*
 * EngineInput.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINEINPUT_H_
#define EHR_COMMON_ENGINEINPUT_H_

#include <einheri/common/Engine.h>

namespace ein {

class Event;

class EngineInput : public Engine{
public:
    EngineInput(GameManager* manager);
    virtual ~EngineInput();

    void apply(const Event& event);
    void frame();

};

}

#endif /* EHR_COMMON_ENGINEINPUT_H_ */
