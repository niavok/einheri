/*
 * Model.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_GAME_MODEL_H_
#define EIN_GAME_MODEL_H_

#include <einheri/common/Vect2.h>
#include <einheri/common/Player.h>
#include <list>

namespace ein {

class GameModel {
public:
    GameModel();
    virtual ~GameModel();

    const std::list<Player *>&  GetPlayers() const { return players; }
    void AddPlayer(Player *newPlayer);

private:
    std::list<Player *> players;

};

}

#endif /* EIN_GAME_MODEL_H_ */
