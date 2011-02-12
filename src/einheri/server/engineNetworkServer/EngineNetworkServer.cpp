/*
 * EngineNetwork.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineNetworkServer.h"
#include <einheri/common/Event.h>

namespace ein {

EngineNetworkServer::EngineNetworkServer(GameManager* manager) : Engine(manager){
    networkServer = new NetworkServer();
    networkServer->Start();
}

EngineNetworkServer::~EngineNetworkServer() {
    networkServer->Stop();
    delete networkServer;
}

void EngineNetworkServer::Apply(const Event& /*event*/) {
}

void EngineNetworkServer::Frame() {
}

}
