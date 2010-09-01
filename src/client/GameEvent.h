/*
 * GameEvent.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef GAMEEVENT_H_
#define GAMEEVENT_H_

#include <map>

namespace einheri {

class GameEvent {
public:

    enum EventType {
        NONE,
        CONNECTED_TO_SERVER,
        REGISTERED_TO_SERVER,
        PLAYER_ADDED,
        HERO_ADDED,
    };

    GameEvent(EventType type);

    enum EventField {
        PLAYER_ID,
        HERO_ID,
    };

    GameEvent();
    virtual ~GameEvent();

    EventType type;
    std::map<EventField, int> intValues;

};

}

#endif /* GAMEEVENT_H_ */
