/*
 * PacketDispatcher.cpp
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */
#include <iostream>

#include "PacketDispatcher.h"
#include "EinheriProtocol.h"
#include "GameEvent.h"
#include "Application.h"

namespace einheri {

PacketDispatcher::PacketDispatcher(Application *application) {
    app = application;
}

PacketDispatcher::~PacketDispatcher() {
    // TODO Auto-generated destructor stub
}

void PacketDispatcher::Start() {
    running = true;
    Launch();
}

void PacketDispatcher::Stop() {
    running = false;
    sf::Packet packet;
    sf::SocketTCP socket;
    packetQueue.PushMessage(packet);
    Wait();
}

void PacketDispatcher::Dispatch(sf::Packet packet, sf::SocketTCP socket) {
    packetQueue.PushMessage(packet);
}

//Private

void PacketDispatcher::Run() {
    std::cout << "PacketDispatcher started" << std::endl;

    sf::Packet packet = packetQueue.PopMessage();

    while (running) {
        EinheriProtocol::ClientCommandType commandType;
        int commandTypeInt;
        packet >> commandTypeInt;

        commandType = (EinheriProtocol::ClientCommandType) commandTypeInt;

        //std::cout<<"PacketDispatcher command "<<EinheriProtocol::getCommandName(commandType)<<std::endl;

        if (!packet) {
            std::cout << "PacketDispatcher bad format" << std::endl;
        }

        switch (commandType) {
        case EinheriProtocol::CLIENT_HELLO:
            dispatchClientHello(&packet);
            break;
        case EinheriProtocol::CLIENT_GOODBYE:
            //TODO
            break;
        case EinheriProtocol::CLIENT_ADD_MONSTER:
            dispatchClientAddMonster(&packet);
            break;
        case EinheriProtocol::CLIENT_ADD_MONSTERS:
            dispatchClientAddMonsters(&packet);
            break;
        case EinheriProtocol::CLIENT_UPDATE_MONSTER:
            dispatchClientUpdateMonster(&packet);
            break;
        case EinheriProtocol::CLIENT_UPDATE_MONSTERS:
            dispatchClientUpdateMonsters(&packet);
            break;
        case EinheriProtocol::CLIENT_ADD_HERO:
            dispatchClientAddHero(&packet);
            break;
        case EinheriProtocol::CLIENT_ADD_HEROES:
            //TODO
            break;
        case EinheriProtocol::CLIENT_UPDATE_HERO:
            //TODO
            break;
        case EinheriProtocol::CLIENT_PLAYER_ADDED:
            dispatchClientPlayerAdded(&packet);
            break;
        case EinheriProtocol::CLIENT_HERO_ADDED:
            dispatchClientHeroAdded(&packet);
            break;
        }

        if (!packet) {
            std::cout << "PacketDispatcher bad format" << std::endl;
        }

        packet = packetQueue.PopMessage();
    }

    std::cout << "PacketDispatcher stopped" << std::endl;
}

void PacketDispatcher::dispatchClientHello(sf::Packet *packet) {
    int majorProtocolVersion;
    int minorProtocolVersion;
    std::string description;

    (*packet) >> majorProtocolVersion >> minorProtocolVersion >> description;
    std::cout << "Server connected. Protocol version : "
            << majorProtocolVersion << "." << minorProtocolVersion
            << ". Description : " << description << std::endl;

    GameEvent gameEvent(GameEvent::REGISTERED_TO_SERVER);
    app->gameEngine.SendEvent(gameEvent);

}

void PacketDispatcher::dispatchClientAddMonsters(sf::Packet *packet) {

    int count;

    (*packet) >> count;
    std::cout << "Add monsters " << count << std::endl;

    app->clientWorldEngine.worldModel->mutexMonsters.Lock();
    for (int i = 0; i < count; i++) {
        int id;
        (*packet) >> id;
        //std::cout<<"Add monster "<<id<<std::endl;
        Monster *monster = new Monster();
        monster->id = id;
        app->clientWorldEngine.worldModel->AddMonster(monster);
    }
    app->clientWorldEngine.worldModel->mutexMonsters.Unlock();
}

void PacketDispatcher::dispatchClientAddMonster(sf::Packet *packet) {
    int id;

    (*packet) >> id;
    //std::cout << "Add monster " << id << std::endl;

    Monster *monster = new Monster();
    monster->id = id;

    app->clientWorldEngine.worldModel->mutexMonsters.Lock();

    app->clientWorldEngine.worldModel->AddMonster(monster);

    app->clientWorldEngine.worldModel->mutexMonsters.Unlock();
}

void PacketDispatcher::dispatchClientUpdateMonster(sf::Packet *packet) {
    int id;
    double speedX;
    double speedY;
    double posX;
    double posY;
    double angle;

    (*packet) >> id >> speedX >> speedY >> posX >> posY >> angle;
    //std::cout<<"Update monster "<<id<<" sx"<<speedX<<" sy"<<speedY<<" px"<<posX<<" py"<<posY<<" a"<<angle<<" "<<std::endl;

    app->clientWorldEngine.worldModel->mutexMonsters.Lock();

    if (app->clientWorldEngine.worldModel->GetMonsters().count(id) > 0) {
        Monster *monster = app->clientWorldEngine.worldModel->GetMonsters().at(
                id);
        monster->angle = angle;
        monster->speedX = speedX;
        monster->speedY = speedY;
        monster->positionX = posX;
        monster->positionY = posY;
    } else {
        std::cout << "Error missing id Updating monster " << id << " sx"
                << speedX << " sy" << speedY << " px" << posX << " py" << posY
                << " a" << angle << " " << std::endl;
    }

    app->clientWorldEngine.worldModel->mutexMonsters.Unlock();
}

void PacketDispatcher::dispatchClientUpdateMonsters(sf::Packet *packet) {

    int count;

    (*packet) >> count;
    //std::cout << "Update monsters " << count << std::endl;

    app->clientWorldEngine.worldModel->mutexMonsters.Lock();
    for (int i = 0; i < count; i++) {
        int id;
        double speedX;
        double speedY;
        double posX;
        double posY;
        double angle;

        (*packet) >> id >> speedX >> speedY >> posX >> posY >> angle;
        //std::cout<<"Update monster "<<id<<" sx"<<speedX<<" sy"<<speedY<<" px"<<posX<<" py"<<posY<<" a"<<angle<<" "<<std::endl;

        if (app->clientWorldEngine.worldModel->GetMonsters().count(id) > 0) {
            Monster *monster =
                    app->clientWorldEngine.worldModel->GetMonsters().at(id);
            monster->angle = angle;
            monster->speedX = speedX;
            monster->speedY = speedY;
            monster->positionX = posX;
            monster->positionY = posY;
        } else {
            std::cout << "Error missing id Updating monster " << id << " sx"
                    << speedX << " sy" << speedY << " px" << posX << " py"
                    << posY << " a" << angle << " " << std::endl;
        }

    }
    app->clientWorldEngine.worldModel->mutexMonsters.Unlock();
}

void PacketDispatcher::dispatchClientAddHero(sf::Packet *packet) {
    int id;

    (*packet) >> id;
    //std::cout << "Add monster " << id << std::endl;

    Hero *hero = new Hero();
    hero->id = id;

    app->clientWorldEngine.worldModel->mutexHeroes.Lock();

    app->clientWorldEngine.worldModel->AddHero(hero);

    app->clientWorldEngine.worldModel->mutexHeroes.Unlock();
}


void PacketDispatcher::dispatchClientPlayerAdded(sf::Packet *packet) {
    int id;

    (*packet) >> id;

    std::cout << "PacketDispatcher::dispatchClientPlayerAdded" << id << std::endl;
    GameEvent gameEvent(GameEvent::PLAYER_ADDED);
    gameEvent.intValues[GameEvent::PLAYER_ID] = id;
    app->gameEngine.SendEvent(gameEvent);
}

void PacketDispatcher::dispatchClientHeroAdded(sf::Packet *packet) {
    int playerId;
    int heroId;

    (*packet) >> playerId >> heroId;

    std::cout << "PacketDispatcher::dispatchClientHeroAdded" << playerId << " " << heroId<< std::endl;
    GameEvent gameEvent(GameEvent::HERO_ADDED);
    gameEvent.intValues[GameEvent::PLAYER_ID] = playerId;
    gameEvent.intValues[GameEvent::HERO_ID] = heroId;
    app->gameEngine.SendEvent(gameEvent);
}


}
