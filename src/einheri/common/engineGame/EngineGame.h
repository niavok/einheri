/*
 * EngineGame.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_ENGINEGAME_H_
#define EIN_ENGINEGAME_H_

#include <einheri/common/Engine.h>
#include <einheri/common/event/EventPrimaryActionBegin.h>
#include <einheri/common/event/EventObjectCollision.h>
#include <list>
#include <einheri/common/engineGame/ProjectileController.h>
#include <einheri/common/event/EventKill.h>
#include <einheri/common/event/EventKilled.h>

namespace ein {

class Event;

class EngineGame : public Engine{
public:
    EngineGame(GameManager* manager);
    virtual ~EngineGame();

    void Apply(const Event& event);
    void Frame();
    std::list<ProjectileController *> GetProjectileControllers() {return projectileControllers; }

private:
    void processEventPrimaryActionBegin(const EventPrimaryActionBegin& event);
    void processEventObjectCollision(const EventObjectCollision& event);
    void processEventKill(const EventKill& event);
    void processEventKilled(const EventKilled& event);

private:
    std::list<ProjectileController *> projectileControllers;
};

}

#endif /* EIN_ENGINEGAME_H_ */
