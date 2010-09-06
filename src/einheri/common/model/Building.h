/*
 * Projectile.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_BUILDING_H_
#define EHR_COMMON_BUILDING_H_

#include "Movable.h"

namespace ein {

class Building: public ein::Movable {
public:
    EIN_DEFINE_VISITABLE()
public:
    Building();
    virtual ~Building();
};

}

#endif /* EHR_COMMON_BUILDING_H_ */
