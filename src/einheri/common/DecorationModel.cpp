/*
 * Model.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "DecorationModel.h"

namespace ein {

DecorationModel::DecorationModel() {

}

DecorationModel::~DecorationModel() {

}

void DecorationModel::AddDecoration(Decoration *newDecoration) {
    decorations.push_back(newDecoration);
}

void DecorationModel::RemoveDecoration(Decoration *decoration) {
    decorations.remove(decoration);
    delete decoration;
}

std::list<Decoration*>::iterator DecorationModel::RemoveDecoration(std::list<Decoration*>::iterator decorationIt) {
    Decoration* decoration = *decorationIt;
    std::list<Decoration*>::iterator it = decorations.erase(decorationIt);
    delete decoration;

    return it;
}

}
