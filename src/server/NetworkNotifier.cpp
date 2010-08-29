/*
 * NetworkNotifier.cpp
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */
#include <iostream>
#include "NetworkNotifier.h"
#include "EinheriProtocol.h"
#include "Application.h"

namespace einheri {

NetworkNotifier::NetworkNotifier(Application *application) {
    this->app = application;
}

NetworkNotifier::~NetworkNotifier() {

}

void NetworkNotifier::AddMonster(Monster * monster) {

    sf::Packet *packetAddMonster = new sf::Packet();
    *packetAddMonster << EinheriProtocol::CLIENT_ADD_MONSTER << monster->id;
    packetQueue.PushMessage(packetAddMonster);

    sf::Packet *packetUpdateMonster = new sf::Packet();
    *packetUpdateMonster << EinheriProtocol::CLIENT_UPDATE_MONSTER
            << monster->id << monster->speedX << monster->speedY
            << monster->positionX << monster->positionY << monster->angle;
    packetQueue.PushMessage(packetUpdateMonster);

}



void NetworkNotifier::UpdateMonster(Monster * monster) {

    sf::Packet *packetUpdateMonster = new sf::Packet();
    *packetUpdateMonster << EinheriProtocol::CLIENT_UPDATE_MONSTER
            << monster->id << monster->speedX << monster->speedY
            << monster->positionX << monster->positionY << monster->angle;
    packetQueue.PushMessage(packetUpdateMonster);

}

void NetworkNotifier::Start() {
    running = true;
    Launch();
}

void NetworkNotifier::Stop() {
    running = false;
    sf::Packet *packet = new sf::Packet();
    packetQueue.PushMessage(packet);
    Wait();
}

//Private

void NetworkNotifier::Run() {
    std::cout << "NetworkNotifier started" << std::endl;

    sf::Packet *packet = packetQueue.PopMessage();

    while (running) {
        std::map<sf::SocketTCP, NetworkClient *>::const_iterator it;

        for (it = app->networkEngine.clients.begin(); it
                != app->networkEngine.clients.end(); it++) {
            NetworkClient * client = it->second;
            client->socket.Send(*packet);
        }
        delete packet;
        packet = packetQueue.PopMessage();

    }
    delete packet;

    std::cout << "NetworkNotifier stopped" << std::endl;
}

}
