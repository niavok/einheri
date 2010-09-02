/*
 * PacketDispatcher.cpp
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */
#include <iostream>

#include "PacketDispatcher.h"
#include "../common/EinheriProtocol.h"
#include "Application.h"

namespace einheriServer {

PacketDispatcher::PacketDispatcher(Application * application) {
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
    socketQueue.PushMessage(NULL);
    packetQueue.PushMessage(packet);
    Wait();
}

void PacketDispatcher::Dispatch(sf::Packet packet, NetworkClient *client) {
    socketQueue.PushMessage(client);
    packetQueue.PushMessage(packet);
}

//Private

void PacketDispatcher::Run() {
    std::cout << "PacketDispatcher started" << std::endl;

    sf::Packet packet = packetQueue.PopMessage();
    NetworkClient *client = socketQueue.PopMessage();

    while (running) {
        einheri::EinheriProtocol::ServerCommandType commandType;
        int commandTypeInt;
        packet >> commandTypeInt;

        commandType = (einheri::EinheriProtocol::ServerCommandType) commandTypeInt;

        std::cout << "PacketDispatcher command " << einheri::EinheriProtocol::getCommandName(commandType) << std::endl;

        switch (commandType) {
        case einheri::EinheriProtocol::SERVER_HELLO:
            dispatchServerHello(&packet, client);
            break;
        case einheri::EinheriProtocol::SERVER_GET_WORLD:
            dispatchServerGetWorld(&packet, client);
            break;
        case einheri::EinheriProtocol::SERVER_ADD_PLAYER:
            dispatchServerGetAddPlayer(&packet, client);
            break;
        case einheri::EinheriProtocol::SERVER_ADD_HERO:
            dispatchServerGetAddHero(&packet, client);
            break;
        case einheri::EinheriProtocol::SERVER_SET_PLAYER_NAME:
            dispatchServerSetPlayerName(&packet, client);
            break;
        case einheri::EinheriProtocol::SERVER_GOODBYE:
            //TODO
            break;
        case einheri::EinheriProtocol::SERVER_UPDATE_HERO_MOVEMENT:
            dispatchServerUpdateHeroMovement(&packet, client);
            break;
        case einheri::EinheriProtocol::SERVER_QUIT:
            //TODO
            break;
        }

        if (!packet) {
            std::cout << "PacketDispatcher bad format" << std::endl;
        }

        packet = packetQueue.PopMessage();
        client = socketQueue.PopMessage();
    }

    std::cout << "PacketDispatcher stopped" << std::endl;
}

void PacketDispatcher::dispatchServerHello(sf::Packet *packet, NetworkClient *client) {
    int majorProtocolVersion;
    int minorProtocolVersion;
    std::string description;

    (*packet) >> majorProtocolVersion >> minorProtocolVersion >> description;
    std::cout << "Client connected. Protocol version : " << majorProtocolVersion << "." << minorProtocolVersion << ". Description : " << description << std::endl;

    app->networkEngine.Hello(client);

}

void PacketDispatcher::dispatchServerGetWorld(sf::Packet */*packet*/, NetworkClient *client) {
    std::cout << "Client want world. Send it." << std::endl;

    app->worldEngine.model.Lock();
    std::vector<Monster *> monsters = app->worldEngine.model.monsters;

    app->networkEngine.AddMonsters(client, monsters);
    app->networkEngine.UpdateMonsters(client, monsters);

    std::vector<Hero *> heroes = app->worldEngine.model.heroes;

    app->networkEngine.AddHeroes(client, heroes);
    app->networkEngine.UpdateHeroes(client, heroes);

    app->worldEngine.model.Unlock();
}

void PacketDispatcher::dispatchServerGetAddPlayer(sf::Packet */*packet*/, NetworkClient *client) {
    GameEvent newPlayerEvent(GameEvent::ADD_PLAYER);
    newPlayerEvent.objectValues[GameEvent::CLIENT] = client;
    app->gameEngine.SendEvent(newPlayerEvent);

}

void PacketDispatcher::dispatchServerGetAddHero(sf::Packet *packet, NetworkClient */*client*/) {
    GameEvent newHeroEvent(GameEvent::ADD_HERO);

    int playerId;
    *packet >> playerId;
    newHeroEvent.intValues[GameEvent::PLAYER_ID] = playerId;
    std::cout << "dispatchServerGetAddHero playerId=" << playerId << std::endl;
    std::cout << "newHeroEvent playerId=" << newHeroEvent.intValues[GameEvent::PLAYER_ID] << std::endl;

    GameEvent newHeroEvent2 = newHeroEvent;

    std::cout << "newHeroEvent2 playerId=" << newHeroEvent2.intValues[GameEvent::PLAYER_ID] << std::endl;

    app->gameEngine.SendEvent(newHeroEvent);

}

void PacketDispatcher::dispatchServerSetPlayerName(sf::Packet */*packet*/, NetworkClient */*client*/) {
    //GameEvent newHeroEvent(GameEvent::ADD_HERO);
    //app->gameEngine.SendEvent(newHeroEvent);

}

void PacketDispatcher::dispatchServerUpdateHeroMovement(sf::Packet *packet, NetworkClient */*client*/) {

    int heroId;
    bool move;
    double angle;
    double speed;
    *packet >> heroId >> move >> angle >> speed;

    std::cout << "dispatchServerUpdateHeroMovement angle=" << angle << std::endl;

    app->worldEngine.model.Lock();
    Hero *hero = app->worldEngine.GetHeroById(heroId);
    if(hero) {
        hero->playerMove = move;
        hero->playerAngle = angle;
        hero->playerSpeed = speed;
    }
    app->worldEngine.model.Unlock();

}

}
