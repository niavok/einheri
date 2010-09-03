/*
 * NetworkNotifier.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef SERVER_NETWORKNOTIFIER_H_
#define SERVER_NETWORKNOTIFIER_H_

#include <vector>
#include <SFML/Network.hpp>
#include "NetworkEngine.h"
#include "../common/MessageQueue.h"
#include "world/Monster.h"
#include "world/Hero.h"
#include "world/Projectile.h"


namespace einheriServer {

class NetworkNotifier : private sf::Thread {
public:
    NetworkNotifier(Application *application);
    virtual ~NetworkNotifier();

    void AddMonster(Monster *monster);
    void AddMonsters(std::vector<Monster *>);
    void UpdateMonster(Monster *monster);
    void StackUpdateMonster(Monster *monster);
    void UpdateMonsters(std::vector<Monster *>);


    void AddHero(Hero *hero);
    void UpdateHero(Hero *hero);
    void UpdateHeroes(std::vector<Hero *>);
    void UpdateHeroAimingAngle(Hero *hero);

    void StackUpdateHero(Hero *hero);

    void AddProjectile(Projectile *bullet);
    void UpdateProjectile(Projectile *bullet);

    void Flush();
    void Start();
    void Stop();

private:
    sf::Mutex flushMutext;
    Application *app;
    virtual void Run();
    bool running;
    MessageQueue<sf::Packet *> packetQueue;
    std::vector<Monster *> monstersToUpdate;
    std::vector<Hero *> heroesToUpdate;
};

}

#endif /* NETWORKNOTIFIER_H_ */
