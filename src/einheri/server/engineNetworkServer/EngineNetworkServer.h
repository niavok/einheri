/*
 * EngineNetwork.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_COMMON_ENGINENETWORKSERVER_H_
#define EIN_COMMON_ENGINENETWORKSERVER_H_

#include <einheri/common/Engine.h>
#include <einheri/server/engineNetworkServer/NetworkServer.h>
#include <einheri/common/event/EventMonsterAdded.h>
#include <einheri/common/event/EventMonsterUpdated.h>

namespace ein {

class Event;

class EngineNetworkServer : public Engine{
public:
    EngineNetworkServer(GameManager* manager);
    virtual ~EngineNetworkServer();

    void Apply(const Event& event);
    void Frame();
    void ProcessMessage(ein::NetworkMessage* message, ein::NetworkDistantNode* sender);
    void processEventMonsterAdded(const EventMonsterAdded& event);
    void processEventMonsterUpdated(const ein::EventMonsterUpdated& event);

private:
    NetworkServer* networkServer;
    
};

}

#endif /* EIN_COMMON_ENGINENETWORKSERVER_H_ */
