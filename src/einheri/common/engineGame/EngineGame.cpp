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

namespace ein {

EngineGame::EngineGame(GameManager* manager) :
	Engine(manager) {
}

EngineGame::~EngineGame() {
}

void EngineGame::Apply(const Event& event) {
	class EngineGameVisitor: public EventVisitor {
	public:
		EngineGameVisitor(EngineGame* engine) :
			engine(engine) {
		}

		void Visit(const EventPrimaryActionUsed& eventPrimaryActionUsed) {
			engine->processEventPrimaryActionUsed(eventPrimaryActionUsed);
		}

		void Visit(const EventObjectCollision& eventObjectCollision) {
			engine->processEventObjectCollision(eventObjectCollision);
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

void EngineGame::processEventPrimaryActionUsed(const EventPrimaryActionUsed& event) {
	Player * player = event.GetPlayer();
	Hero * hero = player->getHero();

	EinValue dist = 0.5;

	Projectile *projectile = new Projectile();
	projectile->SetPosition(Vector(hero->GetPosition().getX() + dist * cos(hero->GetAngle()), hero->GetPosition().getY() + dist * sin(hero->GetAngle())));
	projectile->SetAngle(hero->GetAngle());
	projectile->SetSpeed(Vector(10 * cos(hero->GetAngle()), 10 * sin(hero->GetAngle())));
	projectile->SetTargetedSpeed(projectile->GetSpeed());
	projectile->SetName("Plasma ball");
	manager->GetModel()->AddProjectile(projectile);

	manager->AddEvent(new EventProjectileAdded(projectile));

}

class CollisionVisitor: public einUtils::Visitor<const Movable, std::string> {
public:
	CollisionVisitor() {
		Visit(*this, einUtils::Seq<Hero, Projectile>::Type(), CollisionInvoker());
	}
	virtual ~CollisionVisitor() {
	}

protected:
	virtual std::string GetType(const Movable&) {
		return "Movable";
	}
	virtual std::string GetType(const Hero&) {
		return "Hero";
	}
	virtual std::string GetType(const Projectile&) {
		return "Projectile";
	}

private:
	// Here you can change the name of the Visit method.
	typedef EIN_VISIT_INVOKER( GetType ) CollisionInvoker;
};

void EngineGame::processEventObjectCollision(const EventObjectCollision& event) {

	CollisionVisitor visitor;
	std::cout<<"Collision detected between "<<visitor(*event.GetObject1())<<" and "<<visitor(*event.GetObject2())<<std::endl;
}

}
