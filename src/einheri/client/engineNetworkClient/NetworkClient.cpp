/*
 * NetworkServer.cpp
 *
 */

#include "NetworkClient.h"
#include <SFML/Network.hpp>

namespace ein {

NetworkClient::NetworkClient() {
}

NetworkClient::~NetworkClient() {
}

void NetworkClient::Start(){
    running = true;
    Launch();
}

void NetworkClient::Stop(){
    running = false;
    Wait();
}

//Private

void NetworkClient::Run(){
   std::cout << "NetworkClient started" << std::endl;
    sf::SelectorTCP selector;

    if (clientSocket.Connect(5959, "127.0.0.1") != sf::Socket::Done) {
        std::cout << "NetworkEngine failed to connect to 127.0.0.1 port 5959" << std::endl;
    }

    std::cout << "NetworkEngine connected to 127.0.0.1 port 5959" << std::endl;

    selector.Add(clientSocket);

    while (running) {
        unsigned int nbSockets = selector.Wait(1);

        for (unsigned int i = 0; i < nbSockets; ++i) {
            sf::SocketTCP socket = selector.GetSocketReady(i);

            sf::Packet packet;
            if (socket.Receive(packet) == sf::Socket::Done) {
                //std::cout << "Packet received" << std::endl;
                Dispatch(packet);
            } else {
                std::cout << "A remove client" << std::endl;
                // Erreur : on ferait mieux de retirer le socket du sélecteur
                selector.Remove(socket);
            }

        }

    }
    std::cout << "NetworkClient stopping" << std::endl;
}

void NetworkClient::Dispatch ( sf::Packet packet)
{

}


}