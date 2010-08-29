/*
 * EinheriProtocol.cpp
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#include "EinheriProtocol.h"
#include <sstream>

namespace einheri {

std::string EinheriProtocol::getCommandName(ServerCommandType type) {

    std::stringstream ss;
    ss << (int)type;

    std::string response = "Unknown command ("+ss.str()+")";
    switch(type) {
    case SERVER_HELLO:
        response = "SERVER_HELLO";
        break;
    case SERVER_GOODBYE:
            response = "SERVER_GOODBYE";
            break;
    case SERVER_GET_WORLD:
                response = "SERVER_GET_WORLD";
                break;
    case SERVER_ADD_PLAYER:
                response = "SERVER_ADD_PLAYER";
                break;
    case SERVER_ADD_HERO:
                response = "SERVER_ADD_HERO";
                break;
    }

    return response;
}


std::string EinheriProtocol::getCommandName(ClientCommandType type) {
    std::string response = "Unknown command";
    switch(type) {
    case CLIENT_HELLO:
        response = "CLIENT_HELLO";
        break;
    case CLIENT_GOODBYE:
            response = "CLIENT_GOODBYE";
            break;
    case CLIENT_ADD_MONSTER:
                response = "CLIENT_ADD_MONSTER";
                break;
    case CLIENT_UPDATE_MONSTER:
                response = "CLIENT_UPDATE_MONSTER";
                break;
    }

    return response;
}


}
