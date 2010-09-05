/*
 * MonsterAI.h
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#ifndef EIN_MONSTERAI_H_
#define EIN_MONSTERAI_H_
#include <einheri/common/model/Monster.h>

namespace ein {

class MonsterAI {
public:
    MonsterAI(Monster *monster);
    virtual ~MonsterAI();

    virtual void Compute() = 0;

protected:
    Monster *monster;
};

}

#endif /* EIN_MONSTERAI_H_ */
