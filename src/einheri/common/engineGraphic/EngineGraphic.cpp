/*
 * EngineGraphic.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineGraphic.h"
#include <einheri/common/Event.h>

namespace ein {

EngineGraphic::EngineGraphic(GameManager* manager) : Engine(manager){
}

EngineGraphic::~EngineGraphic() {
}

void EngineGraphic::apply(const Event& /*event*/) {
}

void EngineGraphic::frame() {
}

}
