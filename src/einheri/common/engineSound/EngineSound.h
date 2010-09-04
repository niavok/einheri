/*
 * EnginePhysic.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_ENGINESOUND_H_
#define EIN_ENGINESOUND_H_

#include <einheri/common/Engine.h>

namespace ein {

class Event;

class EngineSound : public Engine{
public:
    EngineSound(GameManager* manager);
    virtual ~EngineSound();

    void Apply(const Event& event);
    void Frame();
private:
    bool playingMusic;
};

}

#endif /* EIN_ENGINESOUND_H_ */
