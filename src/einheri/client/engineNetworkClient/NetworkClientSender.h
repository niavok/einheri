
#ifndef EIN_NETWORKCLIENTSENDER_H_
#define EIN_NETWORKCLIENTSENDER_H_

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <einheri/common/network/messages/NetworkMessage.h>
#include <einheri/common/MessageQueue.h>

namespace ein {

class NetworkClientSender: private sf::Thread {
public:
    NetworkClientSender();
    virtual ~NetworkClientSender();

    void Start();
    void Stop();

    void Send(NetworkMessage* message);
    void SetSocket(sf::SocketTCP socket);
    
private:
    virtual void Run();
    bool running;
    sf::SocketTCP clientSocket;
    MessageQueue<NetworkMessage*> messageQueue;


};

}

#endif /* EIN_NETWORKCLIENTSENDER_H_ */
