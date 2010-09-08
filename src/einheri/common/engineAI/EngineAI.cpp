/*
 * EngineAI.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineAI.h"
#include <einheri/common/Event.h>
#include <einheri/common/event/EventVisitor.h>
#include <einheri/common/engineAI/WanderingMonsterAI.h>
#include <einheri/common/event/EventMonsterAdded.h>
#include "EatTheHeroMonsterAI.h"

namespace ein {

EngineAI::EngineAI(GameManager* manager) : FramerateEngine(manager){
    UseSoftFrameRate(true);
}

EngineAI::~EngineAI() {
    while (!monsterAIs.empty()) {
        MonsterAI* ia = monsterAIs.front();
        delete ia;
        monsterAIs.pop_front();
    }
}

void EngineAI::Apply(const Event& event) {
    class EngineAIVisitor: public EventVisitor {
        public:
            EngineAIVisitor(EngineAI* engine) :
                engine(engine) {
            }

            void Visit(const EventMonsterAdded& eventMonsterAdded) {
                engine->processEventMonsterAdded(eventMonsterAdded);
            }

            void Visit(const EventKill& event) {
                engine->processEventKill(event);
            }

        private:
            EngineAI* engine;
        };
    EngineAIVisitor visitor(this);
        event.accept(visitor);
}

void EngineAI::frame(EinValue /*frameTime*/) {
std::list<MonsterAI *>::const_iterator it;

    for(it = monsterAIs.begin(); it != monsterAIs.end(); ++it) {
        MonsterAI *ai = *it;
        ai->Compute();
    }


}

void EngineAI::processEventMonsterAdded(const EventMonsterAdded& eventMonsterAdded) {
    //WanderingMonsterAI *wanderingMonsterAI = new WanderingMonsterAI(eventMonsterAdded.GetMonster());
    EatTheHeroMonsterAI *monsterAI = new EatTheHeroMonsterAI(manager, eventMonsterAdded.GetMonster());
    monsterAIs.push_back(monsterAI);
}

void EngineAI::processEventKill(const EventKill& event) {
    std::list<MonsterAI *>::iterator it;
    for(it = monsterAIs.begin(); it != monsterAIs.end(); ++it) {
        if(event.GetVictim() == (*it)->GetMonster()) {
            it = monsterAIs.erase(it);
        }
    }
}

}
