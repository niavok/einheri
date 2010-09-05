/*
 * MonsterAI.h
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#ifndef EIN_WANDERING_MONSTERAI_H_
#define EIN_WANDERING_MONSTERAI_H_
#include "MonsterAI.h"

namespace ein {

class WanderingMonsterAI : public MonsterAI {
public:
    WanderingMonsterAI(Monster *monster);
    virtual ~WanderingMonsterAI();

    virtual void Compute();

private:
    EinValue nextComputeTime;
};

}

#endif /* EIN_WANDERING_MONSTERAI_H_ */
