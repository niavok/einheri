/*
 * Protocol.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef EINHERIPROTOCOL_H_
#define EINHERIPROTOCOL_H_

#include <string>

namespace einheri {

class EinheriProtocol {
public:
    enum ServerCommandType {
        SERVER_HELLO = 0, // int major protocol version, int minor protocol version, string infos (os, stats...)
        SERVER_GOODBYE, // string reason

        SERVER_ADD_PLAYER, //
        SERVER_ADD_HERO, // int playerId
        SERVER_SET_PLAYER_NAME, // int playerId, string name

        SERVER_GET_WORLD, //

        SERVER_UPDATE_HERO_MOVEMENT, // int heroId, bool move, double angle, double speed

        SERVER_QUIT,
    };

    enum ClientCommandType {
        CLIENT_HELLO = 0, // int major protocol version, int minor protocol version, string infos (os, stats...)
        CLIENT_GOODBYE, // string reason

        //CLIENT_SET_WORLD, // double sizeX, double size Y
        CLIENT_ADD_HERO, // int id
        CLIENT_ADD_MONSTER, // int id
        CLIENT_ADD_HEROES, // int count, int id, int id ...
        CLIENT_ADD_MONSTERS, // int count, int id, int id ...
        CLIENT_UPDATE_MONSTER, // int id, double speedX, double speedXY, double posX, double posY, double angle
        CLIENT_UPDATE_MONSTERS, // int count, int id, double speedX, double speedXY, double posX, double posY, double angle, ...
        CLIENT_UPDATE_HERO, // int id, double posX, double posY, double angle
        CLIENT_PLAYER_ADDED, // int playerId
        CLIENT_HERO_ADDED // int playerId int heroId
    };

    static std::string getCommandName(ServerCommandType type);
    static std::string getCommandName(ClientCommandType type);


};

}  // namespace einheri

#endif /* EINHERIPROTOCOL_H_ */
