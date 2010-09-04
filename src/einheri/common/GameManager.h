/*
 * GameManager.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_GAMEMANAGER_H_
#define EHR_COMMON_GAMEMANAGER_H_

#include <queue>
#include <vector>
#include <SFML/System/Thread.hpp>

#include <einheri/common/Engine.h>
#include <einheri/common/Event.h>


namespace ein {

class GameManager : public Engine{
public:
    GameManager();
    virtual ~GameManager();

    void Run();

    void AddEvent(Event *);
    void AddEngine(Engine *);

    void apply(const Event& event);
    void frame(){}

private:
    bool running;
    std::queue<Event *> events;
    std::vector<Engine *> engines;
};

}

#endif /* EHR_COMMON_GAMEMANAGER_H_ */
