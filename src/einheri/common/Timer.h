/*
 * Timer.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <einheri/utils/Singleton.h>
#include <einheri/common/Vect2.h>
#include <SFML/System.hpp>
#include <SFML/System/Mutex.hpp>

namespace ein {

class Timer :public einUtils::Singleton<Timer>{
    EIN_SINGLETON(Timer);

    Timer();
    virtual ~Timer();

public:
    EinValue GetGameTime();
    EinValue GetRealTime();

    void PauseGame();
    void StartGame();
    void ResetGameTime();

private:
    void updateTimes();
private:
    bool pause;
    sf::Mutex mutex;
    sf::Clock clock;
    float lastResetClock;
    EinValue gameTime;
    EinValue realTime;


};

}

#endif /* TIMER_H_ */
