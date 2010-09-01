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
#include "EinheriProtocol.h"


namespace einheriServer {

NetworkEngine::NetworkEngine(Application * application) {
    app = application;

}

NetworkEngine::~NetworkEngine() {
    // TODO Auto-generated destructor stub
}


void NetworkEngine::Start(){
    running = true;
    Launch();
}

void NetworkEngine::Stop(){
    running = false;
    Wait();
}


void NetworkEngine::Hello(NetworkClient * client) {
    std::cout<<"Send Hello command"<<std::endl;
        sf::Packet packet;
        int majorProtocolVersion = 45;
        int minorProtocolVersion = 13;
        std::string description = "Einheri server alpha - x86_64 GNU/Linux - ubuntu 10.04";
        int command = einheri::EinheriProtocol::CLIENT_HELLO;

        packet<<command<<majorProtocolVersion<<minorProtocolVersion<<description;
        std::cout<<"command "<<command<<std::endl;
        client->Send(packet);
}

void NetworkEngine::AddMonster(NetworkClient * client, Monster * monster) {
       sf::Packet packet;
       int id = monster->id;
       int command = einheri::EinheriProtocol::CLIENT_ADD_MONSTER;
       packet<<command<<id;
       std::cout<<"Send AddMonster command. id="<<id<<std::endl;
       client->Send(packet);
}

void NetworkEngine::AddMonsters(NetworkClient * client, std::vector<Monster *> monsters) {

    sf::Packet packet;
    packet << einheri::EinheriProtocol::CLIENT_ADD_MONSTERS << (int) monsters.size();
    for(int i = 0; i < (int) monsters.size(); i++) {
        packet << monsters[i]->id;
    }
    client->Send(packet);


}

void NetworkEngine::UpdateMonster(NetworkClient * client, Monster * monster) {
       sf::Packet packet;
       int id = monster->id;
       double speedX = monster->speedX;
       double speedY = monster->speedY;
       double posX = monster->positionX;
       double posY = monster->positionY;
       double angle = monster->angle;

       int command = einheri::EinheriProtocol::CLIENT_UPDATE_MONSTER;
       packet<<command<<id<<speedX<<speedY<<posX<<posY<<angle;
       std::cout<<"Send UpdateMonster command. id="<<id<<std::endl;
       client->Send(packet);
}

void NetworkEngine::UpdateMonsters(NetworkClient * client, std::vector<Monster *> monsters) {

        int id;
        double speedX;
        double speedY;
        double posX;
        double posY;
        double angle;
        sf::Packet packet;

        packet << einheri::EinheriProtocol::CLIENT_UPDATE_MONSTERS << (int) monsters.size();
        for(int i = 0; i < (int)monsters.size(); i++) {

            Monster *monster = monsters[i];

            id = monster->id;
            speedX = monster->speedX;
            speedY = monster->speedY;
            posX = monster->positionX;
            posY = monster->positionY;
            angle = monster->angle;

            packet<<id<<speedX<<speedY<<posX<<posY<<angle;
        }

        std::cout<<"Send UpdateMonsters command. size="<<monsters.size()<<std::endl;
        client->Send(packet);

}

//Private

void NetworkEngine::Run(){
    std::cout<<"NetworkEngine started"<<std::endl;
    sf::SelectorTCP selector;
    sf::SocketTCP listener;

    PacketDispatcher packetDispatcher(app);

    packetDispatcher.Start();

    if (!listener.Listen(5959))
    {
        std::cout<<"NetworkEngine failed to listen on port 5959"<<std::endl;
    }

    selector.Add(listener);


    while(running) {
        unsigned int nbSockets = selector.Wait(1);

        for (unsigned int i = 0; i < nbSockets; ++i)
        {
            sf::SocketTCP socket = selector.GetSocketReady(i);

            if (socket == listener)
                {
                    // Si le socket écouteur est prêt, cela signifie que nous pouvons accepter une nouvelle connexion
                    sf::IPAddress address;
                    sf::SocketTCP clientSocket;
                    listener.Accept(clientSocket, &address);
                    std::cout << "Client connected ! (" << address << ")" << std::endl;

                    NetworkClient *client = new NetworkClient();
                    client->SetSocket(clientSocket);

                    clients[clientSocket] = client;
                    // On l'ajoute au sélecteur
                    selector.Add(clientSocket);
                }
                else
                {


                    // Sinon, il s'agit d'un socket de client et nous pouvons lire les données qu'il nous envoie
                    sf::Packet packet;
                    if (socket.Receive(packet) == sf::Socket::Done)
                    {
                        NetworkClient *client = clients[socket];
                        std::cout << "Packet received" << std::endl;
                        packetDispatcher.Dispatch(packet, client);
                    }
                    else
                    {
                        NetworkClient *client = clients[socket];
                        clients.erase(socket);
                        delete client;
                        std::cout << "A remove client" << std::endl;
                        // Erreur : on ferait mieux de retirer le socket du sélecteur
                        selector.Remove(socket);
                    }
                }


        }

    }
    std::cout<<"NetworkEngine stopping"<<std::endl;

    packetDispatcher.Stop();

    std::cout<<"NetworkEngine stopped"<<std::endl;
}



}
