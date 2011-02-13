/*
 * NetworkServer.cpp
 *
 */

#include "NetworkClient.h"
#include <SFML/Network.hpp>
#include <einheri/common/network/messages/NetworkMessage.h>
#include <einheri/common/network/messages/ServerHelloMessage.h>
#include <einheri/common/network/messages/ClientHelloMessage.h>
#include <einheri/client/engineNetworkClient/EngineNetworkClient.h>
#include <einheri/common/network/messages/ServerWorldPulled.h>
#include <einheri/common/network/messages/ServerAddPlayerMessage.h>

namespace ein {

NetworkClient::NetworkClient(EngineNetworkClient *parentEngine):engine(parentEngine) {
}

NetworkClient::~NetworkClient() {
}

void NetworkClient::Start(){
    running = true;
    clientSender.Start();
    Launch();
}

void NetworkClient::Stop(){
    running = false;
    clientSender.Stop();
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
    clientSender.SetSocket(clientSocket);

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


void NetworkClient::Send(NetworkMessage* message)
{
    clientSender.Send(message);
}



void NetworkClient::Dispatch (sf::Packet packet)
{
    
     NetworkMessage::MessageType messageType = NetworkMessage::ParseMessageType(&packet);
    
    NetworkMessage *genericMessage;
    
    switch(messageType) {
     
        case NetworkMessage::SERVER_HELLO:
        {
            ServerHelloMessage* message = new ServerHelloMessage();
            message->Parse(&packet);
            genericMessage = message;
        }
            break;
        case NetworkMessage::SERVER_WORLD_PULLED:
        {
            ServerWorldPulledMessage* message = new ServerWorldPulledMessage();
            message->Parse(&packet);
            genericMessage = message;
        }
            break;
        case NetworkMessage::SERVER_ADD_PLAYER:
        {
            ServerAddPlayerMessage* message = new ServerAddPlayerMessage();
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
    queueMutex.Unlock();
    
    
}


void NetworkClient::ProcessMessages() {
   queueMutex.Lock(); 
   
   while(!messageQueue.empty()) {
       
       NetworkMessage* message = messageQueue.front();
       
       messageQueue.pop();
       
       
       engine->ProcessMessage(message);
       
       delete message;
   }
   queueMutex.Unlock();
   
}


}