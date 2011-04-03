/*
 * EngineNetwork.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineNetworkClient.h"
#include <einheri/common/Event.h>
#include <einheri/common/GameManager.h>
#include <einheri/common/network/messages/ServerHelloMessage.h>
#include <einheri/common/network/messages/ServerWorldPulled.h>
#include <einheri/common/network/messages/ClientHelloMessage.h>
#include <einheri/common/network/messages/ClientPullWorldMessage.h>
#include <einheri/common/network/messages/ClientCreatePlayerMessage.h>
#include <einheri/common/network/messages/ServerAddPlayerMessage.h>
#include <einheri/common/network/messages/ServerAddMonsterMessage.h>
#include <einheri/common/network/messages/ServerUpdateMonsterMessage.h>
#include <einheri/common/event/EventMonsterAdded.h>
#include <einheri/common/event/EventMonsterUpdated.h>


namespace ein {

EngineNetworkClient::EngineNetworkClient(GameManager* manager) : Engine(manager){
    worldPulledState = false;
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
                networkClient->Send(new ClientPullWorldMessage());
            }
            break;
        case NetworkMessage::SERVER_WORLD_PULLED:
            {
                //ServerWorldPulledMessage* m = (ServerWorldPulledMessage*) message;
                std::cout << "SERVER_WORLD_PULLED received" << std::endl;
                worldPulledState = true;
    
                networkClient->Send(new ClientCreatePlayerMessage("Fred"));
            }
            break;
        case NetworkMessage::SERVER_ADD_PLAYER:
            {
                ServerAddPlayerMessage* m = (ServerAddPlayerMessage*) message;
                std::cout << "SERVER_ADD_PLAYER received" << std::endl;
                    
                Player *player = new Player();
                player->setName(m->playerName);
                player->setId(m->playerId);
                player->setIsLocal(m->isLocal);
                
                manager->GetGameModel()->AddPlayer(player);
            }
            break;
        case NetworkMessage::SERVER_ADD_MONSTER:
            {
                ServerAddMonsterMessage* m = (ServerAddMonsterMessage*) message;
                std::cout << "SERVER_ADD_MONSTER received" << std::endl;
                    
                Monster *monster = new Monster();
                monster->SetId(m->monsterId);
                monster->SetName(m->monsterName);
                monster->SetAngle(m->angle);
                monster->SetPosition(m->position);
                monster->SetRadius(m->radius);
                monster->SetSpeed(m->speed);
                monster->SetTargetedSpeed(m->targetedSpeed);
                //TODO transmit alive parameter
                
                
                manager->GetModel()->AddMonster(monster);
                manager->AddEvent(new EventMonsterAdded(monster));
            }
            break;
        case NetworkMessage::SERVER_UPDATE_MONSTER:
            {
                ServerUpdateMonsterMessage* m = (ServerUpdateMonsterMessage*) message;
                std::cout << "SERVER_UPDATE_MONSTER received" << std::endl;
                
                if(worldPulledState) {
                    Monster *monster = manager->GetModel()->GetMonster(m->monsterId);
                    
                    monster->SetAngle(m->angle);
                    monster->SetPosition(m->position);
                    monster->SetSpeed(m->speed);
                    monster->SetTargetedSpeed(m->targetedSpeed);
                    
                    manager->AddEvent(new EventMonsterUpdated(monster));
                }
            }
            break;
        default:
           break;
        
    }
    
}
}
