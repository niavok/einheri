        /*
 * EngineNetwork.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineNetworkServer.h"
#include <einheri/common/Event.h>
#include <einheri/common/network/messages/ServerHelloMessage.h>

namespace ein {

EngineNetworkServer::EngineNetworkServer(GameManager* manager) : Engine(manager){
    networkServer = new NetworkServer(this);
    networkServer->Start();
}

EngineNetworkServer::~EngineNetworkServer() {
    networkServer->Stop();
    delete networkServer;
}

void EngineNetworkServer::Apply(const Event& /*event*/) {
}

void EngineNetworkServer::Frame() {
    networkServer->ProcessMessages();
}

void EngineNetworkServer::ProcessMessage(NetworkMessage* message, NetworkDistantNode* sender)
{
    
    switch(message->type) {
        
        case NetworkMessage::CLIENT_HELLO:
            {
                ServerHelloMessage* m = (ServerHelloMessage*) message;

                std::cout << "CLIENT_HELLO received from client"<< sender << std::endl;
                std::cout << "protocol version: " << m->majorProtocolVersion << "."<< m->minorProtocolVersion <<std::endl;
                std::cout << "client description: " << m->description <<std::endl;
            }
            break;
        default:
        break;
    }
    
}


}
