/*
 * WorldDrawer.h
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#ifndef EIN_GENERICWORLDDRAWER_H_
#define EIN_GENERICWORLDDRAWER_H_
#include <einheri/common/GameManager.h>

namespace ein {

class GenericWorldDrawer {
public:
    GenericWorldDrawer();
    virtual ~GenericWorldDrawer();

    virtual void Init() = 0;
    virtual void Draw() = 0;
    virtual void Resize(Vector newWindowSize) = 0;


};

}

#endif /* EIN_GENERICWORLDDRAWER_H_ */
