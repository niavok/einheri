/*
 * Player.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef PLAYER_H_
#define PLAYER_H_

namespace einheri {

class Player {
public:
    Player();
    virtual ~Player();

    int id;
    int heroId;
};

}

#endif /* PLAYER_H_ */
