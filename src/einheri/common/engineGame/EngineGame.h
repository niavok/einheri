/*
 * EngineGame.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINEGAME_H_
#define EHR_COMMON_ENGINEGAME_H_

#include <einheri/common/Engine.h>
#include <einheri/common/event/EventPrimaryActionUsed.h>

namespace ein {

class Event;

class EngineGame : public Engine{
public:
    EngineGame(GameManager* manager);
    virtual ~EngineGame();

    void Apply(const Event& event);
    void Frame();

private:
    void processEventPrimaryActionUsed(const EventPrimaryActionUsed& event);
};

}

#endif /* EHR_COMMON_ENGINEGAME_H_ */
