/*
 * GameManager.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include <boost/foreach.hpp>
#include <einheri/utils/Log.h>
#include <einheri/common/event/EventVisitor.h>

#include "GameManager.h"
#include <SFML/System.hpp>

namespace ein {

GameManager::GameManager():Engine(this) {
    running = true;
}

GameManager::~GameManager() {
}

void GameManager::AddEvent(Event * event) {
    events.push(event);
}

void GameManager::AddEngine(Engine *engine) {
    engines.push_back(engine);
}

void GameManager::apply(const Event& event)
{
    class GameManagerVistor : public EventVisitor
    {
    public:
        GameManagerVistor(GameManager* manager):manager(manager){}

        void Visit(const EventWindowClose&)
        {
            manager->running = false;
        }
    private:
        GameManager* manager;
    };
    GameManagerVistor visitor(this);
    event.accept(visitor);
}

void GameManager::Run() {
    LOG("GameManager started ! ");

    AddEngine(this);

    while (running) {
        sf::Sleep(0.2);
        while (!events.empty()) {
            Event *event = events.front();
            events.pop();

            BOOST_FOREACH(Engine * engine, engines) {
                engine->apply(*event);
            }
        }

        BOOST_FOREACH(Engine * engine, engines) {
            engine->frame();
        }

    }

    LOG("GameManager stopped ! ");
    }

}
