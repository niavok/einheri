/*
 * ModelTools.h
 *
 *  Created on: 10 sept. 2010
 *      Author: fred
 */

#ifndef EIN_MODELTOOLS_H_
#define EIN_MODELTOOLS_H_

#include <einheri/utils/Singleton.h>
#include "Movable.h"

namespace ein {

class ModelTools : public einUtils::Singleton<ModelTools>{
    EIN_SINGLETON(ModelTools);
public:
    ModelTools();
    virtual ~ModelTools();

    bool IsMonster(Movable *movable);

};

}

#endif /* EIN_MODELTOOLS_H_ */
