
#ifndef EIN_NETWORKSERVERSENDER_H_
#define EIN_NETWORKSERVERSENDER_H_

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <einheri/common/network/messages/NetworkMessage.h>
#include <einheri/common/MessageQueue.h>
#include <einheri/common/network/NetworkDistantNode.h>


namespace ein {

class NetworkServer;


class NetworkServerSender: private sf::Thread {
public:
    NetworkServerSender(NetworkServer* networkServer);
    virtual ~NetworkServerSender();

    enum SendMode {
            ONE,
            ALL,
            ALL_ELSE_ONE
    };
    
    
    
    void Start();
    void Stop();

    void Send(NetworkDistantNode* receiver, NetworkMessage* message);
    void SendAll(NetworkMessage* message);
    void SendAllElseOne(NetworkDistantNode* client, NetworkMessage* message);
    
private:
    virtual void Run();
    bool running;
    NetworkServer* networkServer;
    MessageQueue<NetworkMessage*> messageQueue;
    MessageQueue<NetworkDistantNode*> clientQueue;
    MessageQueue<SendMode> modeQueue;


};

}

#endif /* EIN_NETWORKSERVERSENDER_H_ */
