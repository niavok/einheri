/*
 * EngineGraphic.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINEGRAPHIC_H_
#define EHR_COMMON_ENGINEGRAPHIC_H_

#include <einheri/common/Engine.h>

namespace ein {

class Event;

class EngineGraphic : public Engine{
public:
    EngineGraphic(GameManager* manager);
    virtual ~EngineGraphic();

    void apply(const Event& event);
    void frame();

};

}

#endif /* EHR_COMMON_ENGINEGRAPHIC_H_ */
