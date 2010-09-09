/*
 * Model.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_DECORATION_MODEL_H_
#define EIN_DECORATION_MODEL_H_

#include <einheri/common/Vect2.h>
#include <einheri/common/Decoration.h>
#include <list>

namespace ein {

class DecorationModel {
public:
    DecorationModel();
    virtual ~DecorationModel();

    std::list<Decoration *>&  GetDecorations() { return decorations; }
    void AddDecoration(Decoration *newDecorationModel);
    void RemoveDecoration(Decoration *decoration);
    std::list<Decoration*>::iterator RemoveDecoration(std::list<Decoration*>::iterator decorationIt);


private:
    std::list<Decoration *> decorations;

};

}

#endif /* EIN_GAME_MODEL_H_ */
