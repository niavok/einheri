/*
 * IdGenerator.cpp
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#include "IdGenerator.h"

namespace einheriServer {

int IdGenerator::nextId = 1;

IdGenerator::IdGenerator() {
    // TODO Auto-generated constructor stub

}

IdGenerator::~IdGenerator() {
    // TODO Auto-generated destructor stub
}
int IdGenerator::GetId(){
    int id = nextId;
    nextId++;
    return id;
}

}
