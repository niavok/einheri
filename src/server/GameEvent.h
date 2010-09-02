/*
 * GameEvent.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef SERVER_GAMEEVENT_H_
#define SERVER_GAMEEVENT_H_

#include <map>

namespace einheriServer {

class GameEvent {
public:

    enum EventType {
        NONE,
        ADD_PLAYER,
        ADD_HERO
    };

    GameEvent(EventType type);



    enum EventField {
        PLAYER_ID,
        HERO_ID,
        CLIENT
    };

    GameEvent();
    virtual ~GameEvent();

    EventType type;
    std::map<EventField, int> intValues;
    std::map<EventField, void *> objectValues;
};

}

#endif /* GAMEEVENT_H_ */
