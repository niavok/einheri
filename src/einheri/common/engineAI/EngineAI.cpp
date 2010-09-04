/*
 * EngineAI.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineAI.h"
#include <einheri/common/Event.h>

namespace ein {

EngineAI::EngineAI(GameManager* manager) : Engine(manager){
}

EngineAI::~EngineAI() {
}

void EngineAI::apply(const Event& /*event*/) {
}

void EngineAI::frame() {
}

}
