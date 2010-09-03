/*
 * ConnexionListener.cpp
 *
 *  Created on: 28 août 2010
 *      Author: fred
 */

#include <iostream>
#include <SFML/Network.hpp>

#include "NetworkEngine.h"
#include "PacketDispatcher.h"
#include "../common/EinheriProtocol.h"
#include "GameEvent.h"
#include "Application.h"

namespace einheri {

NetworkEngine::NetworkEngine(Application *application) {
    app = application;
}

NetworkEngine::~NetworkEngine() {
}

void NetworkEngine::Start() {
    running = true;
    Launch();
}

void NetworkEngine::Stop() {
    running = false;
    Wait();
}

void NetworkEngine::Hello() {
    std::cout << "Send Hello command" << std::endl;
    sf::Packet packet;
    int majorProtocolVersion = 45;
    int minorProtocolVersion = 13;
    std::string description = "Einheri alpha - x86_64 GNU/Linux - ubuntu 10.04";
    int command = EinheriProtocol::SERVER_HELLO;

    packet << command << majorProtocolVersion << minorProtocolVersion << description;
    std::cout << "command " << command << std::endl;
    clientSocket.Send(packet);
}

void NetworkEngine::GetWorld() {
    std::cout << "Send GetWorld command" << std::endl;
    sf::Packet packet;

    int command = EinheriProtocol::SERVER_GET_WORLD;
    packet << command;
    std::cout << "command " << command << std::endl;
    clientSocket.Send(packet);
}

void NetworkEngine::AddPlayer() {
    std::cout << "Send AddPlayer command" << std::endl;
    sf::Packet packet;

    int command = EinheriProtocol::SERVER_ADD_PLAYER;
    packet << command;
    std::cout << "command " << command << std::endl;
    clientSocket.Send(packet);
}

void NetworkEngine::AddHero(int playerId) {
    std::cout << "Send AddHero command" << std::endl;
    sf::Packet packet;

    int command = EinheriProtocol::SERVER_ADD_HERO;
    packet << command << playerId;
    std::cout << "command " << command << std::endl;
    clientSocket.Send(packet);
}

void NetworkEngine::SetPlayerName(int playerId, std::string name) {
    std::cout << "Send SetPlayerName command" << std::endl;
    sf::Packet packet;

    int command = EinheriProtocol::SERVER_SET_PLAYER_NAME;
    packet << command << playerId << name;
    std::cout << "command " << command << std::endl;
    clientSocket.Send(packet);
}

void NetworkEngine::UpdateHeroMovement(int heroId, bool move, double angle, double speed) {
    //std::cout << "Send UpdateHero command" << std::endl;
    sf::Packet packet;

    int command = EinheriProtocol::SERVER_UPDATE_HERO_MOVEMENT;
    packet << command << heroId << move << angle << speed;
    //std::cout << "command UpdateHeroMovement heroId=" << heroId << " move=" << move<< " angle=" << angle<< " speed=" << speed << std::endl;
    clientSocket.Send(packet);
}

void NetworkEngine::UpdateHeroAimingAngle(int heroId, double angle) {
    //std::cout << "Send UpdateHeroAimingAngle command" << std::endl;
    sf::Packet packet;

    int command = EinheriProtocol::SERVER_UPDATE_HERO_AIMING_ANGLE;
    packet << command << heroId << angle ;
    //std::cout << "command UpdateHeroAimingAngle heroId=" << heroId << " angle=" << angle << std::endl;
    clientSocket.Send(packet);
}

void NetworkEngine::UseMainAction(int heroId, Vect2<double> cursor) {
    std::cout << "Send UseMainAction command" << std::endl;
    sf::Packet packet;

    int command = EinheriProtocol::SERVER_HERO_USE_MAIN_ACTION;
    packet << command << heroId << cursor.getX() << cursor.getY();
    std::cout << "command UpdateHeroAimingAngle heroId=" << heroId << " cursor.x=" << cursor.getX() << " cursor.y=" << cursor.getY() << std::endl;
    clientSocket.Send(packet);
}

//Private

void NetworkEngine::Run() {
    std::cout << "NetworkEngine started" << std::endl;
    sf::SelectorTCP selector;

    PacketDispatcher packetDispatcher(app);

    packetDispatcher.Start();

    //if (clientSocket.Connect(5959, "192.168.0.12") != sf::Socket::Done) {
    if (clientSocket.Connect(5959, "127.0.0.1") != sf::Socket::Done) {
        std::cout << "NetworkEngine failed to connect to 127.0.0.1 port 5959" << std::endl;
    }

    std::cout << "NetworkEngine connected to 127.0.0.1 port 5959" << std::endl;

    selector.Add(clientSocket);

    GameEvent gameEvent;
    gameEvent.type = GameEvent::CONNECTED_TO_SERVER;
    app->gameEngine.SendEvent(gameEvent);

    while (running) {
        unsigned int nbSockets = selector.Wait(1);

        for (unsigned int i = 0; i < nbSockets; ++i) {
            sf::SocketTCP socket = selector.GetSocketReady(i);

            sf::Packet packet;
            if (socket.Receive(packet) == sf::Socket::Done) {
                //std::cout << "Packet received" << std::endl;
                packetDispatcher.Dispatch(packet, socket);
            } else {
                std::cout << "A remove client" << std::endl;
                // Erreur : on ferait mieux de retirer le socket du sélecteur
                selector.Remove(socket);
            }

        }

    }
    std::cout << "NetworkEngine stopping" << std::endl;

    packetDispatcher.Stop();

    std::cout << "NetworkEngine stopped" << std::endl;
}

}
