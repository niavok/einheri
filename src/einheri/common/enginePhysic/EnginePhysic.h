/*
 * EnginePhysic.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINEPPHYSIC_H_
#define EHR_COMMON_ENGINEPPHYSIC_H_

#include <einheri/common/Engine.h>

namespace ein {

class Event;

class EnginePhysic : public Engine{
public:
    EnginePhysic(GameManager* manager);
    virtual ~EnginePhysic();

    void Apply(const Event& event);
    void Frame();

};

}

#endif /* EHR_COMMON_ENGINEPPHYSIC_H_ */
