/*
 * EnginePhysic.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_ENGINESOUND_H_
#define EIN_ENGINESOUND_H_

#include <einheri/common/FramerateEngine.h>
#include <SFML/Audio.hpp>
#include <list>
#include "einheri/common/event/EventProjectileAdded.h"

namespace ein {

class Event;

class EngineSound : public FramerateEngine{
public:
    EngineSound(GameManager* manager);
    virtual ~EngineSound();

    void Apply(const Event& event);
private:
    void frame(EinValue framerate);

    void processEventProjectileAdded(const EventProjectileAdded& eventProjectileAdded);

private:
    sf::Music *music;
    std::list<sf::Sound*> sounds;
    sf::SoundBuffer fireSoundBuffer;

};

}

#endif /* EIN_ENGINESOUND_H_ */
