/*
 * EnginePhysic.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "FramerateEngine.h"
#include <einheri/common/Event.h>
#include "einheri/common/Timer.h"

namespace ein {

FramerateEngine::FramerateEngine(GameManager* manager) : Engine(manager){
    nextFrameTime = 0;
    useGameTime = true;
    useSoftFrameRate = true;
    preferredFrameTime = 1./60.;
}

FramerateEngine::~FramerateEngine() {
}


void FramerateEngine::Frame() {
    EinValue currentTime;

    if(useGameTime) {
        currentTime = Timer::get().GetGameTime();
    } else {
        currentTime = Timer::get().GetRealTime();
    }

    while(currentTime > nextFrameTime) {
        frame(preferredFrameTime);
        if(useSoftFrameRate) {
            nextFrameTime = currentTime + preferredFrameTime;
        }else {
            nextFrameTime += preferredFrameTime;
        }
    }
}

}
