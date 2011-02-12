/*
 * EnginePlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINEDECORATON_H_
#define EHR_COMMON_ENGINEDECORATON_H_

#include <einheri/common/FramerateEngine.h>
#include <einheri/common/event/EventKill.h>
#include <einheri/common/ClientGameManager.h>

namespace ein {

class Event;

class EngineDecoration : public FramerateEngine{
public:
    EngineDecoration(ClientGameManager* manager);
    virtual ~EngineDecoration();

    void Apply(const Event& event);

    void processEventKill(const EventKill& event);

private:
    ClientGameManager* clientManager;
    void frame(EinValue framerate);


};

}

#endif /* EHR_COMMON_ENGINEDECORATON_H_ */
