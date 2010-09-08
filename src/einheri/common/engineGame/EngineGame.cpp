/*
 * EngineGame.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineGame.h"
#include <einheri/common/Event.h>
#include <iostream>
#include "einheri/common/Timer.h"
#include <einheri/common/event/EventWindowClose.h>
#include <einheri/common/GameManager.h>
#include <math.h>
#include "einheri/common/event/EventHeroAdded.h"
#include <einheri/common/event/EventVisitor.h>
#include "einheri/common/event/EventProjectileAdded.h"

#include <typeinfo>
#include "einheri/utils/Sequance.h"
#include <einheri/common/event/EventKilled.h>
#include "PlasmaBallController.h"

namespace ein {

EngineGame::EngineGame(GameManager* manager) :
    Engine(manager) {
    projectileControllers.push_back(new PlasmaBallController(manager));
}

EngineGame::~EngineGame() {
    while (!projectileControllers.empty()) {
        ProjectileController* controller = projectileControllers.front();

        delete controller;

        projectileControllers.pop_front();
    }
}

void EngineGame::Apply(const Event& event) {
    class EngineGameVisitor: public EventVisitor {
    public:
        EngineGameVisitor(EngineGame* engine) :
            engine(engine) {
        }

        void Visit(const EventPrimaryActionBegin& eventPrimaryActionBegin) {
            engine->processEventPrimaryActionBegin(eventPrimaryActionBegin);
        }

        void Visit(const EventObjectCollision& eventObjectCollision) {
            engine->processEventObjectCollision(eventObjectCollision);
        }

        void Visit(const EventKill& event) {
            engine->processEventKill(event);
        }

        void Visit(const EventKilled& event) {
            engine->processEventKilled(event);
        }

    private:
        EngineGame* engine;
    };
    EngineGameVisitor visitor(this);
    event.accept(visitor);
}

int plop = 0;
void EngineGame::Frame() {
    //std::cout << "Real " << Timer::get().GetRealTime() << std::endl;
    //std::cout << "Game " << Timer::get().GetGameTime() << std::endl;
    if (Timer::get().GetRealTime() > plop) {
        /*if (plop % 2 == 1) {
         Timer::get().PauseGame();
         std::cout << "pause" << std::endl;
         std::cout << "Real " << Timer::get().GetRealTime() << std::endl;
         std::cout << "Game " << Timer::get().GetGameTime() << std::endl;
         std::cout << "" << std::endl;
         } else {
         Timer::get().StartGame();
         std::cout << "start" << std::endl;
         std::cout << "Real " << Timer::get().GetRealTime() << std::endl;
         std::cout << "Game " << Timer::get().GetGameTime() << std::endl;
         std::cout << "" << std::endl;
         }*/
        plop++;
    }

    if (manager->GetGameModel()->GetPlayers().empty()) {
        Player * player = new Player();
        manager->GetGameModel()->AddPlayer(player);
        Hero * hero = new Hero();
        manager->GetModel()->AddHero(hero);

        player->setHero(hero);
        manager->AddEvent(new EventHeroAdded(hero));
    } else {
        Player * player = manager->GetGameModel()->GetPlayers().front();
        Hero * hero = player->getHero();

        if (player->getWantMove()) {
            EinValue moveAngle = player->getWantedAngle();
            EinValue speedFactor = player->getWantedSpeed() * 0.02;
            hero->SetTargetedSpeed(Vector(cos(moveAngle) * speedFactor, sin(moveAngle) * speedFactor));
        } else {
            hero->SetTargetedSpeed(Vector(0, 0));
        }

        Vector cursor = manager->GetCameraModel()->Pick(manager->GetInputModel()->GetMouse());

        double heroX = hero->GetPosition().getX();
        double heroY = hero->GetPosition().getY();

        double angleX = cursor.getX() - heroX;
        double angleY = cursor.getY() - heroY;

        double aimingAngle = atan2(angleY, angleX);

        hero->SetAngle(aimingAngle);

    }

}

void EngineGame::processEventPrimaryActionBegin(const EventPrimaryActionBegin& event) {
    Player * player = event.GetPlayer();
    Hero * hero = player->getHero();

    EinValue dist = 1.2;
    EinValue dist2 = -0.3;

    Projectile *projectile = new PlasmaBall();
    projectile->SetPosition(Vector(
            hero->GetPosition().getX() + dist2 * cos(hero->GetAngle()+0.83)+ dist * cos(hero->GetAngle()) ,
            hero->GetPosition().getY() + dist2 * sin(hero->GetAngle()+0.83)+ dist * sin(hero->GetAngle())));
    projectile->SetAngle(hero->GetAngle());
    projectile->SetSpeed(Vector(10 * cos(hero->GetAngle()), 10 * sin(hero->GetAngle())));
    projectile->SetTargetedSpeed(projectile->GetSpeed());
    projectile->SetName("Plasma ball");
    projectile->SetShooter(hero);
    manager->GetModel()->AddProjectile(projectile);

    manager->AddEvent(new EventProjectileAdded(projectile));

}

class CollisionVisitor: public einUtils::Visitor<const Movable> {
public:
       CollisionVisitor(EngineGame* engine, Movable *collider):engine(engine), collider(collider) {
       Visit(*this, einUtils::Seq<Hero, Projectile, Monster, PlasmaBall>::Type(), CollisionInvoker());
   }
   virtual ~CollisionVisitor() {
   }

protected:
   virtual void ProcessEvent(const Movable& movable) {
   }

   virtual void ProcessEvent(const Monster&) {

   }

   virtual void ProcessEvent(const Hero&) {

   }
   virtual void ProcessEvent(const Projectile& projectile) {
        std::list<ProjectileController *>::iterator it;
        for (it = engine->GetProjectileControllers().begin(); it != engine->GetProjectileControllers().end(); it++) {
            ProjectileController* controller = *it;
            if (controller->processCollision(const_cast<Projectile *> (&projectile), collider)) {
                break;
            }

        }
       std::cout << "Collision with projectile end" << std::endl;

   }

private:
   // Here you can change the name of the Visit method.
   typedef EIN_VISIT_INVOKER( ProcessEvent ) CollisionInvoker;
   EngineGame* engine;
   Movable* collider;
};

void EngineGame::processEventObjectCollision(const EventObjectCollision& event) {
    CollisionVisitor visitor1(this,event.GetObject2());
    visitor1(*event.GetObject1());
    CollisionVisitor visitor2(this,event.GetObject1());
    visitor2(*event.GetObject2());

    //std::cout<<"Collision detected between "<<visitor(*event.GetObject1())<<" and "<<visitor(*event.GetObject2())<<std::endl;
}

void EngineGame::processEventKill(const EventKill& event) {
    if(event.GetVictim()->IsAlive()) {
        event.GetVictim()->SetAlive(false);
        manager->AddEvent(new EventKilled(event.GetVictim()));
    }
}

void EngineGame::processEventKilled(const EventKilled& event){
    std::cout<<"EngineGame::processEventKilled killed"<<event.GetVictim()<<std::endl;
    manager->GetModel()->Remove(event.GetVictim());
}

}
