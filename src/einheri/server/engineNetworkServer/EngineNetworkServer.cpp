        /*
 * EngineNetwork.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineNetworkServer.h"
#include <einheri/common/Event.h>
#include <einheri/common/network/messages/ClientHelloMessage.h>
#include <einheri/common/network/messages/ClientCreatePlayerMessage.h>
#include <einheri/common/network/messages/ServerWorldPulled.h>
#include <einheri/common/network/messages/ServerAddPlayerMessage.h>
#include <einheri/common/GameManager.h>
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

                ClientHelloMessage* m = (ClientHelloMessage*) message;

                std::cout << "CLIENT_HELLO received from client"<< sender << std::endl;
                std::cout << "protocol version: " << m->majorProtocolVersion << "."<< m->minorProtocolVersion <<std::endl;
                std::cout << "client description: " << m->description <<std::endl;
            }
            break;
        case NetworkMessage::CLIENT_PULL_WORLD:
            {
                //ServerHelloMessage* m = (ServerHelloMessage*) message;

                std::cout << "CLIENT_PULL_WORLD received from client"<< sender << std::endl;

                networkServer->SendMessageToClient(sender, new ServerWorldPulledMessage());
            }
            break;
        case NetworkMessage::CLIENT_CREATE_PLAYER:
            {

                ClientCreatePlayerMessage* m = (ClientCreatePlayerMessage*) message;

                std::cout << "CLIENT_CREATE_PLAYER received from client"<< sender << std::endl;
                std::cout << "client player name: " << m->playerName <<std::endl;
                Player* player = new Player();
                player->setName(m->playerName);
                //TODO: set id
                

                manager->GetGameModel()->AddPlayer(player);
                
                networkServer->SendMessageToClient(sender, new ServerAddPlayerMessage(player->getId(), true, player->getName()));
                networkServer->SendMessageToAllElseOneClient(sender, new ServerAddPlayerMessage(player->getId(), false, player->getName()));
            }
            break;
        default:
        break;
    }
    
}


}
