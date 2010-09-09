/*
 * ModelTools.cpp
 *
 *  Created on: 10 sept. 2010
 *      Author: fred
 */

#include "ModelTools.h"
#include <einheri/common/model/Monster.h>

namespace ein {

ModelTools::ModelTools() {
    // TODO Auto-generated constructor stub

}

ModelTools::~ModelTools() {
    // TODO Auto-generated destructor stub
}

class IsMonsterVisitor: public einUtils::Visitor<const Movable, bool> {
public:
    IsMonsterVisitor() {
        Visit(*this, einUtils::Seq<Movable, Monster>::Type(), CollisionInvoker());
    }
    virtual ~IsMonsterVisitor() {
    }

protected:
    virtual bool IsMonster(const Movable&) {
        return false;

    }

    virtual bool IsMonster(const Monster&) {
        return true;
    }

private:
    // Here you can change the name of the Visit method.
typedef EIN_VISIT_INVOKER( IsMonster ) CollisionInvoker;

};

bool ModelTools::IsMonster(Movable *movable) {
    IsMonsterVisitor visitor;
    return visitor(*movable);
}

}
