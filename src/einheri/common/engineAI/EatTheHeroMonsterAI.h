/*
 * MonsterAI.h
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#ifndef EIN_EATTHEHERO_MONSTERAI_H_
#define EIN_EATTHEHERO_MONSTERAI_H_
#include "MonsterAI.h"

namespace ein {

class EatTheHeroMonsterAI : public MonsterAI {
public:
    EatTheHeroMonsterAI(GameManager *manager, Monster *monster);
    virtual ~EatTheHeroMonsterAI();

    virtual void Compute();

private:
    EinValue nextComputeTime;
};

}

#endif /* EIN_EATTHEHERO_MONSTERAI_H_ */
