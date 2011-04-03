/*
 * EnginePlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EnginePlayer.h"
#include <einheri/common/Event.h>
#include <einheri/common/event/EventVisitor.h>
#include "einheri/common/event/EventKeyPressed.h"
#include "einheri/common/event/EventKeyReleased.h"
#include "einheri/common/event/EventMouseButtonPressed.h"
#include "einheri/common/event/EventMouseButtonReleased.h"
#include <einheri/common/Player.h>
#include <list>
#include <einheri/common/GameManager.h>
#include <einheri/utils/Log.h>
#include <einheri/common/event/EventPrimaryActionBegin.h>
#include <einheri/common/event/EventQuitGame.h>

namespace ein {

EnginePlayer::EnginePlayer(ClientGameManager* manager) :
    Engine(manager) {
    clientManager = manager;
}

EnginePlayer::~EnginePlayer() {
}

void EnginePlayer::Apply(const Event& event) {
    class EnginePlayerVisitor: public EventVisitor {
    public:
        EnginePlayerVisitor(EnginePlayer* engine) :
            engine(engine) {
        }

        void Visit(const EventKeyPressed& eventKeyPressed) {
            engine->processEventKeyPressed(eventKeyPressed);
            engine->refleshPlayersAction();
        }

        void Visit(const EventKeyReleased& eventKeyReleased) {
            engine->processEventKeyReleased(eventKeyReleased);
            engine->refleshPlayersAction();
        }

        void Visit(const EventMouseButtonPressed& eventMouseButtonPressed) {
            engine->processEventMouseButtonPressed(eventMouseButtonPressed);
            engine->refleshPlayersAction();
        }

        void Visit(const EventMouseButtonReleased& eventMouseButtonReleased) {
            engine->processEventMouseButtonReleased(eventMouseButtonReleased);
            engine->refleshPlayersAction();
        }
    private:
        EnginePlayer* engine;
    };
    EnginePlayerVisitor visitor(this);
    event.accept(visitor);
}

void EnginePlayer::Frame() {
    
    std::list<Player *>::const_iterator it;
    
    const std::list<Player *>& players = manager->GetGameModel()->GetPlayers();
    
    for (it = players.begin(); it != players.end(); ++it) {
        Player * player = *it;
        if (!player->getIsLocal() || player->getHero() == NULL) {
            continue;
        }
        
        player->getHero()->SetFocusPosition(clientManager->GetCameraModel()->Pick(clientManager->GetInputModel()->GetMouse()));
    }
}

//private

void EnginePlayer::refleshPlayersAction() {

    std::list<Player *>::const_iterator it;

    const std::list<Player *>& players = manager->GetGameModel()->GetPlayers();

    for (it = players.begin(); it != players.end(); ++it) {
        Player * player = *it;
        if (!player->getIsLocal()) {
            continue;
        }

        bool left = clientManager->GetInputModel()->GetKeyState(sf::Key::Q);
        bool right = clientManager->GetInputModel()->GetKeyState(sf::Key::D);
        bool up = clientManager->GetInputModel()->GetKeyState(sf::Key::Z);
        bool down = clientManager->GetInputModel()->GetKeyState(sf::Key::S);

        double angle = 0;
        bool move = left || right || up || down;
        double speed = 100; //With keyboard, speed is always 0% or 100%

        if (left && !right && !up && !down) {
            angle = M_PI;
        }

        if (left && !right && up && !down) {
            angle = 3 * M_PI / 4;
        }

        if (!left && !right && up && !down) {
            angle = M_PI / 2;
        }

        if (!left && right && up && !down) {
            angle = M_PI / 4;
        }

        if (!left && right && !up && !down) {
            angle = 0;
        }

        if (!left && right && !up && down) {
            angle = -M_PI / 4;
        }

        if (!left && !right && !up && down) {
            angle = -M_PI / 2;
        }

        if (left && !right && !up && down) {
            angle = -3 * M_PI / 4;
        }

        player->setWantedAngle(angle);
        player->setWantedSpeed(speed);
        player->setWantMove(move);

    }

}

void EnginePlayer::processEventKeyPressed(const EventKeyPressed& event) {
    if (event.getKeyCode()  == sf::Key::Escape) {
        manager->AddEvent(new EventQuitGame());
    }

}
void EnginePlayer::processEventKeyReleased(const EventKeyReleased& /*event*/) {
}

void EnginePlayer::processEventMouseButtonPressed(const EventMouseButtonPressed& event) {
    Player * player = manager->GetGameModel()->GetPlayers().front();
        if(player) {

            if(event.getMouseButton() == sf::Mouse::Left) {
                manager->AddEvent(new EventPrimaryActionBegin(player));
            }
        }

}
void EnginePlayer::processEventMouseButtonReleased(const EventMouseButtonReleased& event) {
    Player * player = manager->GetGameModel()->GetPlayers().front();
    if(player) {

        if(event.getMouseButton() == sf::Mouse::Left) {
            manager->AddEvent(new EventPrimaryActionEnd(player));
        }
    }
}



}

