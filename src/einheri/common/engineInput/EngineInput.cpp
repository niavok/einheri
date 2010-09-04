/*
 * EngineInput.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineInput.h"
#include <einheri/common/Event.h>

namespace ein {

EngineInput::EngineInput(GameManager* manager) : Engine(manager){
}

EngineInput::~EngineInput() {
}

void EngineInput::Apply(const Event& /*event*/) {
}

void EngineInput::Frame() {
}

}
