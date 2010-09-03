/*
 * ConnexionListener.h
 *
 *  Created on: 28 août 2010
 *      Author: fred
 */

#ifndef SERVER_NETWORKENGINE_H_
#define SERVER_NETWORKENGINE_H_

#include <SFML/System.hpp>
#include "NetworkClient.h"
#include "world/Monster.h"
#include "world/Hero.h"

namespace einheriServer {

class Application;

class NetworkEngine : private sf::Thread {
public:
    NetworkEngine(Application * application);
    virtual ~NetworkEngine();

    void Start();
    void Stop();
    void Hello(NetworkClient * client);
    void AddMonster(NetworkClient * client, Monster * monster);
    void UpdateMonster(NetworkClient * client, Monster * monster);
    void AddMonsters(NetworkClient * client, std::vector<Monster *> monsters);
    void UpdateMonsters(NetworkClient * client, std::vector<Monster *> monsters);
    void PlayerAdded(NetworkClient * client, int id);
    void HeroAdded(NetworkClient * client, int playerid, int heroId);

    void AddHeroes(NetworkClient * client, std::vector<Hero *> heroes);
    void UpdateHeroes(NetworkClient * client, std::vector<Hero *> heroes);


    std::map<sf::SocketTCP, NetworkClient *> clients;

private:
    Application * app;
       virtual void Run();
       bool running;



};

}

#endif /* NETWORKENGINE_H_ */
