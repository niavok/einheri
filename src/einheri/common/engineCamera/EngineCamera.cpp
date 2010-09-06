/*
 * EnginePhysic.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineCamera.h"
#include <einheri/common/Event.h>
#include <einheri/utils/Log.h>
#include <einheri/common/event/EventVisitor.h>
#include <einheri/common/GameManager.h>


namespace ein {

EngineCamera::EngineCamera(GameManager* manager) :
    FramerateEngine(manager) {
    UseGameTime(true);
    UseSoftFrameRate(true);



}

EngineCamera::~EngineCamera() {


}

void EngineCamera::Apply(const Event& /*event*/) {

}

void EngineCamera::frame(EinValue) {

    if (!manager->GetGameModel()->GetPlayers().empty()) {
                     Player * player = manager->GetGameModel()->GetPlayers().front();
            Hero * hero = player->getHero();

            manager->GetCameraModel()->SetPosition(hero->GetPosition());
    }
}


}
