/*
 * MonsterAI.h
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#ifndef EIN_MONSTERAI_H_
#define EIN_MONSTERAI_H_
#include <einheri/common/model/Monster.h>
#include <einheri/common/GameManager.h>

namespace ein {

class MonsterAI {
public:
    MonsterAI(GameManager *manager, Monster *monster);
    virtual ~MonsterAI();

    virtual void Compute() = 0;

    Monster *GetMonster() { return monster; }

protected:
    Monster *monster;
    GameManager *manager;
};

}

#endif /* EIN_MONSTERAI_H_ */
