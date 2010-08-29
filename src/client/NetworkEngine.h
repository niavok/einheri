/*
 * ConnexionListener.h
 *
 *  Created on: 28 août 2010
 *      Author: fred
 */

#ifndef NETWORKENGINE_H_
#define NETWORKENGINE_H_

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

namespace einheri {

class Application;

class NetworkEngine : private sf::Thread {
public:
    NetworkEngine(Application *application);
    virtual ~NetworkEngine();

    void Start();
    void Stop();

    void GetWorld();
    void Hello();

   private:
       Application *app;
       virtual void Run();
       bool running;
       sf::SocketTCP clientSocket;




};

}

#endif /* NETWORKENGINE_H_ */
