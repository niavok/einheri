/*
 * Projectile.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_PLAYER_H_
#define EIN_PLAYER_H_
#include <einheri/common/model/Hero.h>
#include <string>

namespace ein {

class Player {
public:
    Player();
    virtual ~Player();

    Hero *getHero() const {
        return hero;
    }

    bool getIsLocal() const {
        return isLocal;
    }

    std::string getName() const {
        return name;
    }

    bool getWantMove() const {
        return wantMove;
    }

    EinValue getWantedAngle() const {
        return wantedAngle;
    }

    EinValue getWantedSpeed() const {
        return wantedSpeed;
    }

    void setHero(Hero *hero) {
        this->hero = hero;
    }

    void setIsLocal(bool isLocal) {
        this->isLocal = isLocal;
    }

    void setName(std::string name) {
        this->name = name;
    }

    void setWantMove(bool wantMove) {
        this->wantMove = wantMove;
    }

    void setWantedAngle(EinValue wantedAngle) {
        this->wantedAngle = wantedAngle;
    }

    void setWantedSpeed(EinValue wantedSpeed) {
        this->wantedSpeed = wantedSpeed;
    }

private:
    std::string name;
    bool isLocal;
    Hero *hero;

    bool wantMove;
    EinValue wantedSpeed;
    EinValue wantedAngle;
};

}

#endif /* EIN_PLAYER_H_ */
