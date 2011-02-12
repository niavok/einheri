
#include "NetworkClientSender.h"

#include <iostream>

namespace ein {

NetworkClientSender::NetworkClientSender(){
    
}

NetworkClientSender::~NetworkClientSender() {
}

void NetworkClientSender::Start(){
    running = true;
    Launch();
}

void NetworkClientSender::Stop(){
    running = false;
    messageQueue.PushMessage(NULL);
    Wait();
}

//Private

void NetworkClientSender::Run(){
   std::cout << "NetworkClientSender started" << std::endl;
   
   NetworkMessage* message;
   
   message = messageQueue.PopMessage();
   
    while (running) {
        sf::Packet p;
        message->Generate(&p);
        clientSocket.Send(p);
        std::cout << "packet send" << std::endl;
        delete message;
        
        message = messageQueue.PopMessage();
    }
    std::cout << "NetworkClientSender stopping" << std::endl;
}

void NetworkClientSender::Send(NetworkMessage* message)
{
    std::cout << "NetworkClientSender message queued" << std::endl;
    messageQueue.PushMessage(message);
}

void NetworkClientSender::SetSocket(sf::SocketTCP socket)
{
    clientSocket = socket;
}


}