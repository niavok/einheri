/*
 * Projectile.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_HERO_H_
#define EHR_COMMON_HERO_H_

#include "Movable.h"

namespace ein {

class Hero: public ein::Movable {
public:
    EIN_DEFINE_VISITABLE()
public:
    Hero();
    virtual ~Hero();
    
    Vector GetFocusPosition() const {
        return focusPosition;
    }
    
    void SetFocusPosition(Vector newFocusPosition) {
        focusPosition = newFocusPosition;
    }
    
private:
    Vector focusPosition;
};

}

#endif /* EHR_COMMON_HERO_H_ */
