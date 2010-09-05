/*
 * EnginePlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINEPLAYER_H_
#define EHR_COMMON_ENGINEPLAYER_H_

#include <einheri/common/Engine.h>
#include <einheri/common/event/EventKeyPressed.h>
#include <einheri/common/event/EventKeyReleased.h>
#include <einheri/common/event/EventMouseButtonReleased.h>
#include <einheri/common/event/EventMouseButtonPressed.h>

namespace ein {

class Event;

class EnginePlayer : public Engine{
public:
    EnginePlayer(GameManager* manager);
    virtual ~EnginePlayer();

    void Apply(const Event& event);
    void Frame();

private:

    void refleshPlayersAction();

    void processEventKeyPressed(const EventKeyPressed& event);
    void processEventKeyReleased(const EventKeyReleased& event);
    void processEventMouseButtonPressed(const EventMouseButtonPressed& event);
    void processEventMouseButtonReleased(const EventMouseButtonReleased& event);

};

}

#endif /* EHR_COMMON_ENGINEPLAYER_H_ */
