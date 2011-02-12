/*
 * EngineNetwork.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineNetworkClient.h"
#include <einheri/common/Event.h>

namespace ein {

EngineNetworkClient::EngineNetworkClient(GameManager* manager) : Engine(manager){
    networkClient = new NetworkClient();
    networkClient->Start();
}

EngineNetworkClient::~EngineNetworkClient() {
    networkClient->Stop();
    delete networkClient;
}

void EngineNetworkClient::Apply(const Event& /*event*/) {
}

void EngineNetworkClient::Frame() {
}

}
