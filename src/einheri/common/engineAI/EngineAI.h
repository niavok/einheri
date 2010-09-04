/*
 * EngineAI.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef ENGINEAI_H_
#define ENGINEAI_H_

#include <einheri/common/Engine.h>

namespace ein {

class Event;

class EngineAI : public Engine{
public:
    EngineAI(GameManager* manager);
    virtual ~EngineAI();

    void apply(const Event& event);
    void frame();

};

}

#endif /* ENGINEAI_H_ */
