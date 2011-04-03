/*
 * NetworkServer.cpp
 *
 */

#include "NetworkServer.h"
#include <SFML/Network.hpp>
#include <einheri/common/network/messages/ServerHelloMessage.h>
#include <einheri/common/network/messages/ClientHelloMessage.h>
#include <einheri/common/network/messages/ClientCreatePlayerMessage.h>
#include <einheri/common/network/messages/ClientPullWorldMessage.h>
#include <einheri/server/engineNetworkServer/EngineNetworkServer.h>

namespace ein {

NetworkServer::NetworkServer(EngineNetworkServer *parentEngine):
serverSender(this),
engine(parentEngine)
{
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
                    
                    SendMessageToClient(client, new ServerHelloMessage());
                }
                else
                {


                    // Sinon, il s'agit d'un socket de client et nous pouvons lire les données qu'il nous envoie
                    sf::Packet packet;
                    if (socket.Receive(packet) == sf::Socket::Done)
                    {
                        NetworkDistantNode *client = clients[socket];
                        //std::cout << "Packet received" << std::endl;
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



void NetworkServer::SendMessageToClient(NetworkDistantNode* sender, NetworkMessage* message)
{
    serverSender.Send(sender, message);
}

void NetworkServer::SendMessageToAll(NetworkMessage* message)
{
    serverSender.SendAll(message);
}

void NetworkServer::SendMessageToAllElseOneClient(NetworkDistantNode* sender, NetworkMessage* message)
{
    serverSender.SendAllElseOne(sender, message);
}

void NetworkServer::Dispatch ( sf::Packet packet, NetworkDistantNode* sender )
{
    NetworkMessage::MessageType messageType = NetworkMessage::ParseMessageType(&packet);
    
    NetworkMessage *genericMessage;
    
    switch(messageType) {
     
        case NetworkMessage::CLIENT_HELLO:
        {
            ClientHelloMessage* message = new ClientHelloMessage();
            message->Parse(&packet);
            genericMessage = message;
        }
            break;
        case NetworkMessage::CLIENT_PULL_WORLD:
        {
            ClientPullWorldMessage* message = new ClientPullWorldMessage();
            message->Parse(&packet);
            genericMessage = message;
        }
            break;
        case NetworkMessage::CLIENT_CREATE_PLAYER:
        {

            ClientCreatePlayerMessage* message = new ClientCreatePlayerMessage();
            message->Parse(&packet);
            genericMessage = message;
        }
            break;
        default:
            std::cout << "Protocol failure: invalid message type: "<< messageType << std::endl;
             break;
    }
    
    queueMutex.Lock();
    messageQueue.push(genericMessage);
    clientQueue.push(sender);
    queueMutex.Unlock();
    
    
}


void NetworkServer::ProcessMessages() {
    queueMutex.Lock(); 
   
   while(!messageQueue.empty()) {
       
       NetworkMessage* message = messageQueue.front();
       NetworkDistantNode* sender = clientQueue.front();
       
       messageQueue.pop();
       clientQueue.pop();
       
       
       engine->ProcessMessage(message, sender);
   }
   queueMutex.Unlock();
   
}

}