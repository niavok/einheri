/*
 * EngineNetwork.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineNetwork.h"
#include <einheri/common/Event.h>

namespace ein {

EngineNetwork::EngineNetwork(GameManager* manager) : Engine(manager){
}

EngineNetwork::~EngineNetwork() {
}

void EngineNetwork::Apply(const Event& /*event*/) {
}

void EngineNetwork::Frame() {
}

}
