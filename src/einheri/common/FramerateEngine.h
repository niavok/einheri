/*
 * EnginePhysic.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_COMMON_FRAMERATEENGINE_H_
#define EIN_COMMON_FRAMERATEENGINE_H_

#include <einheri/common/Engine.h>
#include <einheri/common/Vect2.h>

namespace ein {

class Event;

class FramerateEngine : public Engine{
public:
    FramerateEngine(GameManager* manager);
    virtual ~FramerateEngine();

    //Frames will be skip if the game is paused
    void UseGameTime(bool use) { useGameTime = use; }

    //Frames will be skip if the engine is late
    void UseSoftFrameRate(bool use) { useSoftFrameRate = use; }

    void Frame();
protected:
    virtual void frame(EinValue frameTime) = 0;

private:
    bool useGameTime;
    bool useSoftFrameRate;
    EinValue preferredFrameTime;
    EinValue nextFrameTime;

};

}

#endif /* EIN_COMMON_FRAMERATEENGINE_H_ */
