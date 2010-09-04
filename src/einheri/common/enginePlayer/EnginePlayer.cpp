/*
 * EnginePlayer.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EnginePlayer.h"
#include <einheri/common/Event.h>

namespace ein {

EnginePlayer::EnginePlayer(GameManager* manager) : Engine(manager){
}

EnginePlayer::~EnginePlayer() {
}

void EnginePlayer::Apply(const Event& /*event*/) {
}

void EnginePlayer::Frame() {
}

}
