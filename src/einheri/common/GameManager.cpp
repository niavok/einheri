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
#include <einheri/common/event/EventQuitGame.h>

namespace ein {

GameManager::GameManager() :
    Engine(this) {
    running = true;
    model = new Model();
    
    gameModel = new GameModel();
    
}

GameManager::~GameManager() {
    delete gameModel;
   
    delete model;

    while (!events.empty()) {
        Event* event = events.front();
        delete event;
        events.pop();
    }
}

void GameManager::AddEvent(Event * event) {
    events.push(event);
}

void GameManager::AddEngine(Engine *engine) {
    engines.push_back(engine);
}

void GameManager::Apply(const Event& event) {
    class GameManagerVisitor: public EventVisitor {
    public:
        GameManagerVisitor(GameManager* manager) :
            manager(manager) {
        }

        void Visit(const EventWindowClose&) {
            manager->running = false;
        }
        
        void Visit(const EventQuitGame&) {
            manager->running = false;
        }
        
    private:
        GameManager* manager;
    };
    GameManagerVisitor visitor(this);
    event.accept(visitor);
}

void GameManager::Run() {
    LOG("GameManager started ! ");

    AddEngine(this);

    while (running) {
        sf::Sleep(0.0001);

        BOOST_FOREACH(Engine * engine, engines)
        {
            engine->Frame();
        }

        while (!events.empty()) {
            Event *event = events.front();
            events.pop();

            BOOST_FOREACH(Engine * engine, engines)
            {
                engine->Apply(*event);
            }
            delete event;
        }

    }

    LOG("GameManager stopped ! ");
    BOOST_FOREACH(Engine * engine, engines)
    {
        if (engine != this) {
            delete engine;
        }
    }

}

}
