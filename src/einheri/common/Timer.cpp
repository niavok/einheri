/*
 * Timer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "Timer.h"
#include <einheri/utils/ScopedLock.h>
#include <iostream>

namespace ein {

Timer::Timer() {
    pause = false;
    lastResetClock = 0.f;
    gameTime = 0.;
    realTime = 0.;
    clock.Reset();
}

Timer::~Timer() {
}

EinValue Timer::GetGameTime() {
    einUtils::ScopedLock l(mutex);
    updateTimes();
    return gameTime;
}
EinValue Timer::GetRealTime() {
    einUtils::ScopedLock l(mutex);
    updateTimes();
    return realTime;
}

void Timer::PauseGame() {
    einUtils::ScopedLock l(mutex);
    updateTimes();
    pause = true;
}
void Timer::StartGame() {
    einUtils::ScopedLock l(mutex);
    updateTimes();
    pause = false;
}
void Timer::ResetGameTime() {
    einUtils::ScopedLock l(mutex);
    updateTimes();
    gameTime = 0;
}

void Timer::updateTimes() {
    float elapsed = clock.GetElapsedTime();

    if (!pause) {
        gameTime += elapsed - lastResetClock;
    }
    realTime += elapsed - lastResetClock;
    if (elapsed < 2) {
        lastResetClock = elapsed ;
    } else {
        lastResetClock = 0;
        clock.Reset();
    }
}

}
