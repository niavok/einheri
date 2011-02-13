
#include "NetworkServerSender.h"


#include <iostream>
#include "NetworkServer.h"

namespace ein {

NetworkServerSender::NetworkServerSender(NetworkServer* networkServer){
    this->networkServer = networkServer;
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
    modeQueue.PushMessage(ALL);
    Wait();
}

//Private

void NetworkServerSender::Run(){
   std::cout << "NetworkServerSender started" << std::endl;
   
   NetworkMessage* message;
   NetworkDistantNode* client;
   SendMode mode;
   
   message = messageQueue.PopMessage();
   client = clientQueue.PopMessage();
   mode = modeQueue.PopMessage();
   
    while (running) {
        switch(mode) {
            case ONE:
                client->Send(message);
                break;
            case ALL:
            {
                std::map<sf::SocketTCP, NetworkDistantNode *>::iterator it;
                for(it=networkServer->clients.begin(); it != networkServer->clients.end(); it ++) {
                    it->second->Send(message);
                }
            }
                break;
            case ALL_ELSE_ONE:
            {
                std::map<sf::SocketTCP, NetworkDistantNode *>::iterator it;
                for(it=networkServer->clients.begin(); it != networkServer->clients.end(); it ++) {
                    if(it->second != client) {
                        it->second->Send(message);
                    }
                }
            }
                break;
        }
        
        delete message;
        
        message = messageQueue.PopMessage();
        client = clientQueue.PopMessage();
        mode = modeQueue.PopMessage();
        
    }
    std::cout << "NetworkServerSender stopping" << std::endl;
}

void NetworkServerSender::Send(NetworkDistantNode* client, NetworkMessage* message)
{
    messageQueue.PushMessage(message);
    clientQueue.PushMessage(client);
    modeQueue.PushMessage(ONE);
}

void NetworkServerSender::SendAll(NetworkMessage* message)
{
    messageQueue.PushMessage(message);
    clientQueue.PushMessage(NULL);
    modeQueue.PushMessage(ALL);
}

void NetworkServerSender::SendAllElseOne(NetworkDistantNode* client, NetworkMessage* message)
{
    messageQueue.PushMessage(message);
    clientQueue.PushMessage(client);
    modeQueue.PushMessage(ALL_ELSE_ONE);
}


}