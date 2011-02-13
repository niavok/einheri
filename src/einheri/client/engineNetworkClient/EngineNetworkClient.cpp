/*
 * EngineNetwork.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineNetworkClient.h"
#include <einheri/common/Event.h>
#include <einheri/common/network/messages/ServerHelloMessage.h>
#include <einheri/common/network/messages/ClientHelloMessage.h>

namespace ein {

EngineNetworkClient::EngineNetworkClient(GameManager* manager) : Engine(manager){
    networkClient = new NetworkClient(this);
    networkClient->Start();
}

EngineNetworkClient::~EngineNetworkClient() {
    networkClient->Stop();
    delete networkClient;
}

void EngineNetworkClient::Apply(const Event& /*event*/) {
}

void EngineNetworkClient::Frame() {
    networkClient->ProcessMessages();
}

void EngineNetworkClient::ProcessMessage(NetworkMessage* message)
{

    switch(message->type) {
        
        case NetworkMessage::SERVER_HELLO:
            {
                ServerHelloMessage* m = (ServerHelloMessage*) message;
                std::cout << "SERVER_HELLO received" << std::endl;
                std::cout << "protocol version: " << m->majorProtocolVersion << "."<< m->minorProtocolVersion <<std::endl;
                std::cout << "server description: " << m->description <<std::endl;
                    
                networkClient->Send(new ClientHelloMessage());
            }
            break;
        default:
           break;
        
    }
    
}
}
