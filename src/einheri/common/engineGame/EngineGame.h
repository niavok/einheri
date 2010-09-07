/*
 * EngineGame.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINEGAME_H_
#define EHR_COMMON_ENGINEGAME_H_

#include <einheri/common/Engine.h>
#include <einheri/common/event/EventPrimaryActionBegin.h>
#include <einheri/common/event/EventObjectCollision.h>
#include <list>
#include <einheri/common/engineGame/ProjectileController.h>

namespace ein {

class Event;

class EngineGame : public Engine{
public:
    EngineGame(GameManager* manager);
    virtual ~EngineGame();

    void Apply(const Event& event);
    void Frame();

private:
    void processEventPrimaryActionBegin(const EventPrimaryActionBegin& event);
    void processEventObjectCollision(const EventObjectCollision& event);

private:
    std::list<ProjectileController *> projectileControllers;
};

}

#endif /* EHR_COMMON_ENGINEGAME_H_ */
