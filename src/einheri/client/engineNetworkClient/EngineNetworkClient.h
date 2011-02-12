/*
 * EngineNetwork.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_COMMON_ENGINENETWORKCLIENT_H_
#define EIN_COMMON_ENGINENETWORKCLIENT_H_

#include <einheri/common/Engine.h>
#include "NetworkClient.h"

namespace ein {

class Event;

class EngineNetworkClient : public Engine{
public:
    EngineNetworkClient(GameManager* manager);
    virtual ~EngineNetworkClient();

    void Apply(const Event& event);
    void Frame();

private:
    NetworkClient* networkClient;
    
};

}

#endif /* EIN_COMMON_ENGINENETWORKCLIENT_H_ */
