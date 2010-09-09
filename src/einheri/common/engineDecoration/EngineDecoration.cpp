/*
 * EnginePlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineDecoration.h"
#include <einheri/common/GameManager.h>
#include <einheri/utils/Log.h>
#include <einheri/common/event/EventVisitor.h>
#include "einheri/common/Timer.h"
#include "einheri/common/model/ModelTools.h"

namespace ein {

EngineDecoration::EngineDecoration(GameManager* manager) :
    FramerateEngine(manager) {
}

EngineDecoration::~EngineDecoration() {
}

void EngineDecoration::Apply(const Event& event) {
    class EngineDecorationVisitor: public EventVisitor {
    public:
        EngineDecorationVisitor(EngineDecoration* engine) :
            engine(engine) {
        }

        void Visit(const EventKill& event) {
            engine->processEventKill(event);
        }


    private:
        EngineDecoration* engine;
    };
    EngineDecorationVisitor visitor(this);
    event.accept(visitor);
}


//private

void EngineDecoration::frame(EinValue /*framerate*/) {
    std::list<Decoration *>::iterator it;

    for (it = manager->GetDecorationModel()->GetDecorations().begin(); it != manager->GetDecorationModel()->GetDecorations().end(); ++it) {
        Decoration *decoration = *it;
        if(Timer::get().GetGameTime() > decoration->GetEndTime()) {
            it  = manager->GetDecorationModel()->RemoveDecoration(it);
        }
    }
}


void EngineDecoration::processEventKill(const EventKill& event) {
    Movable* movable = event.GetVictim();

    if(ModelTools::get().IsMonster(movable)) {

        Decoration *decoration = new Decoration(Decoration::BLOOD);
        decoration->SetPosition(movable->GetPosition());
        decoration->SetGraphic(0);
        decoration->SetAngle(sf::Randomizer::Random((float)-M_PI,(float)M_PI));
        EinValue time = Timer::get().GetGameTime();
        decoration->SetBeginTime(time);
        decoration->SetEndTime(time + 60);

        manager->GetDecorationModel()->AddDecoration(decoration);
    }
}

}

