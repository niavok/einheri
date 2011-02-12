/*
 * NetworkServer.cpp
 *
 */

#include "NetworkServer.h"
#include <SFML/Network.hpp>
#include <einheri/common/network/messages/ServerHelloMessage.h>

namespace ein {

NetworkServer::NetworkServer() {
}

NetworkServer::~NetworkServer() {
}

void NetworkServer::Start(){
    running = true;
    serverSender.Start();
    Launch();
}

void NetworkServer::Stop(){
    running = false;
    serverSender.Stop();
    Wait();
}

//Private

void NetworkServer::Run(){
    std::cout<<"NetworkServer started"<<std::endl;
    sf::SelectorTCP selector;
    sf::SocketTCP listener;


    if (!listener.Listen(5959))
    {
        std::cout<<"NetworkEngine failed to listen on port 5959"<<std::endl;
    }

    selector.Add(listener);


    while(running) {
        std::cout<<"wait"<<std::endl;
    
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

                    NetworkDistantNode *client = new NetworkDistantNode();
                    client->SetSocket(clientSocket);

                    clients[clientSocket] = client;
                    // On l'ajoute au sélecteur
                    selector.Add(clientSocket);
                    
                    Send(client, new ServerHelloMessage());
                }
                else
                {


                    // Sinon, il s'agit d'un socket de client et nous pouvons lire les données qu'il nous envoie
                    sf::Packet packet;
                    if (socket.Receive(packet) == sf::Socket::Done)
                    {
                        NetworkDistantNode *client = clients[socket];
                        std::cout << "Packet received" << std::endl;
                        Dispatch(packet, client);
                    }
                    else
                    {
                        NetworkDistantNode *client = clients[socket];
                        clients.erase(socket);
                        delete client;
                        std::cout << "A remove client" << std::endl;
                        // Erreur : on ferait mieux de retirer le socket du sélecteur
                        selector.Remove(socket);
                    }
                }


        }

    }
    
    
    std::cout<<"NetworkServer stopped"<<std::endl;
}



void NetworkServer::Send(NetworkDistantNode* sender, NetworkMessage* message)
{
    serverSender.Send(sender, message);
}


static void processClientHelloMessage(sf::Packet* packet, NetworkDistantNode* sender)
{
    ServerHelloMessage message;
    message.Parse(packet);

    std::cout << "CLIENT_HELLO received from client"<< sender << std::endl;
    std::cout << "protocol version: " << message.majorProtocolVersion << "."<< message.minorProtocolVersion <<std::endl;
    std::cout << "client description: " << message.description <<std::endl;
    
}



void NetworkServer::Dispatch ( sf::Packet packet, NetworkDistantNode* sender )
{
    NetworkMessage::MessageType messageType = NetworkMessage::ParseMessageType(&packet);
    
    switch(messageType) {
     
        case NetworkMessage::CLIENT_HELLO:
            processClientHelloMessage(&packet, sender);
            break;
        default:
            std::cout << "Protocol failure: invalid message type: "<< messageType << std::endl;
             break;
    }
    
}


}