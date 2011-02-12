
#ifndef EIN_NETWORKSERVERSENDER_H_
#define EIN_NETWORKSERVERSENDER_H_

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <einheri/common/network/messages/NetworkMessage.h>
#include <einheri/common/MessageQueue.h>
#include <einheri/common/network/NetworkDistantNode.h>

namespace ein {

class NetworkServerSender: private sf::Thread {
public:
    NetworkServerSender();
    virtual ~NetworkServerSender();

    void Start();
    void Stop();

    void Send(NetworkDistantNode* receiver, NetworkMessage* message);
    
private:
    virtual void Run();
    bool running;
    MessageQueue<NetworkMessage*> messageQueue;
    MessageQueue<NetworkDistantNode*> clientQueue;


};

}

#endif /* EIN_NETWORKSERVERSENDER_H_ */
