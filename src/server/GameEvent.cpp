/*
 * GameEvent.cpp
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#include "GameEvent.h"

namespace einheriServer {

GameEvent::GameEvent():
        type(GameEvent::NONE){
}

GameEvent::GameEvent(EventType type):
type(type){

}

GameEvent::~GameEvent() {

}

}
