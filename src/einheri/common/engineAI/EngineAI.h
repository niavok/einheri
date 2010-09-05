/*
 * EngineAI.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_ENGINEAI_H_
#define EIN_ENGINEAI_H_

#include <einheri/common/FramerateEngine.h>
#include <einheri/common/event/EventMonsterAdded.h>
#include <list>
#include "MonsterAI.h"

namespace ein {

class Event;

class EngineAI : public FramerateEngine{
public:
    EngineAI(GameManager* manager);
    virtual ~EngineAI();

    void Apply(const Event& event);


private:
    void frame(EinValue frameTime);
    void processEventMonsterAdded(const EventMonsterAdded& eventMonsterAdded);

private:
    std::list<MonsterAI *> monsterAIs;
};

}

#endif /* EIN_ENGINEAI_H_ */
