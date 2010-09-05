/*
 * EnginePhysic.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_ENGINESOUND_H_
#define EIN_ENGINESOUND_H_

#include <einheri/common/Engine.h>
#include <SFML/Audio.hpp>

namespace ein {

class Event;

class EngineSound : public Engine{
public:
    EngineSound(GameManager* manager);
    virtual ~EngineSound();

    void Apply(const Event& event);
    void Frame();
private:
    sf::Music *music;
};

}

#endif /* EIN_ENGINESOUND_H_ */
