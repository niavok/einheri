/*
 * Model.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "GameModel.h"

namespace ein {

GameModel::GameModel() {

}

GameModel::~GameModel() {

}

void GameModel::AddPlayer(Player *newPlayer) {
    players.push_back(newPlayer);
}

}
