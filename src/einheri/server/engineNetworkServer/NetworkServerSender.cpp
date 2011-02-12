
#include "NetworkServerSender.h"

#include <iostream>

namespace ein {

NetworkServerSender::NetworkServerSender(){
    
}

NetworkServerSender::~NetworkServerSender() {
}

void NetworkServerSender::Start(){
    running = true;
    Launch();
}

void NetworkServerSender::Stop(){
    running = false;
    messageQueue.PushMessage(NULL);
    clientQueue.PushMessage(NULL);
    Wait();
}

//Private

void NetworkServerSender::Run(){
   std::cout << "NetworkServerSender started" << std::endl;
   
   NetworkMessage* message;
   NetworkDistantNode* client;
   
   message = messageQueue.PopMessage();
   client = clientQueue.PopMessage();
   
    while (running) {
        client->Send(message);
        
        message = messageQueue.PopMessage();
        client = clientQueue.PopMessage();
    }
    std::cout << "NetworkServerSender stopping" << std::endl;
}

void NetworkServerSender::Send(NetworkDistantNode* client, NetworkMessage* message)
{
    messageQueue.PushMessage(message);
    clientQueue.PushMessage(client);
}


}