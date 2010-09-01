/*
 * Player.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef SERVER_PLAYER_H_
#define SERVER_PLAYER_H_

#include "NetworkClient.h"

namespace einheriServer {

class Hero;

class Player {
public:
    Player();
    virtual ~Player();
    int id;
    NetworkClient * client;
    Hero * hero;
};

}

#endif /* PLAYER_H_ */
