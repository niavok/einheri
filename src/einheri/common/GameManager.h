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
#include <einheri/common/Model.h>


namespace ein {

class GameManager : public Engine{
public:
    GameManager();
    virtual ~GameManager();

    void Run();

    void AddEvent(Event *);
    void AddEngine(Engine *);

    void Apply(const Event& event);
    void Frame(){}

    Model* GetModel() { return model; }

private:
    bool running;
    std::queue<Event*> events;
    std::vector<Engine*> engines;
    Model* model;
};

}

#endif /* EHR_COMMON_GAMEMANAGER_H_ */
