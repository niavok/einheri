/*
 * PacketDispatcher.cpp
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */
#include <iostream>

#include "PacketDispatcher.h"
#include "EinheriProtocol.h"
#include "Application.h"

namespace einheri {

PacketDispatcher::PacketDispatcher(Application * application) {
    app = application;
}

PacketDispatcher::~PacketDispatcher() {
    // TODO Auto-generated destructor stub
}

void PacketDispatcher::Start(){
    running = true;
    Launch();
}

void PacketDispatcher::Stop(){
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

void PacketDispatcher::Run(){
    std::cout<<"PacketDispatcher started"<<std::endl;

    sf::Packet packet = packetQueue.PopMessage();
    NetworkClient *client = socketQueue.PopMessage();


    while(running) {
        EinheriProtocol::ServerCommandType commandType;
        int commandTypeInt;
        packet >> commandTypeInt;

        commandType = (EinheriProtocol::ServerCommandType) commandTypeInt;

        std::cout<<"PacketDispatcher command "<<EinheriProtocol::getCommandName(commandType)<<std::endl;

        switch (commandType) {
            case EinheriProtocol::SERVER_HELLO:
                dispatchServerHello(&packet, client);
                break;
            case EinheriProtocol::SERVER_GET_WORLD:
                dispatchServerGetWorld(&packet, client);
                break;
        }

        if(!packet){
            std::cout<<"PacketDispatcher bad format"<<std::endl;
        }

        packet = packetQueue.PopMessage();
        client = socketQueue.PopMessage();
    }

    std::cout<<"PacketDispatcher stopped"<<std::endl;
}

void PacketDispatcher::dispatchServerHello(sf::Packet *packet, NetworkClient *client){
    int command;
    int majorProtocolVersion;
    int minorProtocolVersion;
    std::string description;

    (*packet)>>majorProtocolVersion>>minorProtocolVersion>>description;
    std::cout<<"Client connected. Protocol version : "<<majorProtocolVersion<<"."<<minorProtocolVersion<<". Description : " <<description<<std::endl;

    app->networkEngine.Hello(client);

}

void PacketDispatcher::dispatchServerGetWorld(sf::Packet *packet, NetworkClient *client){
    std::cout<<"Client want world. Send it."<<std::endl;


    std::vector<Monster *> monsters = app->worldEngine.model.monsters;

    app->networkEngine.AddMonsters(client, monsters);
    app->networkEngine.UpdateMonsters(client, monsters);

}

}
