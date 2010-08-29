/*
 * GameEvent.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef GAMEEVENT_H_
#define GAMEEVENT_H_

namespace einheri {

class GameEvent {
public:

    enum EventType {
        NONE,
        CONNECTED_TO_SERVER,
        REGISTERED_TO_SERVER,
    };

    GameEvent();
    virtual ~GameEvent();

    EventType type;

};

}

#endif /* GAMEEVENT_H_ */
