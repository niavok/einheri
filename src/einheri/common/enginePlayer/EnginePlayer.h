/*
 * EnginePlayer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINEPLAYER_H_
#define EHR_COMMON_ENGINEPLAYER_H_

#include <einheri/common/Engine.h>

namespace ein {

class Event;

class EnginePlayer : public Engine{
public:
    EnginePlayer(GameManager* manager);
    virtual ~EnginePlayer();

    void apply(const Event& event);
    void frame();

};

}

#endif /* EHR_COMMON_ENGINEPLAYER_H_ */
