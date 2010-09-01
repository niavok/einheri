/*
 * IdGenerator.cpp
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#include "IdGenerator.h"

namespace einheriServer {

int IdGenerator::nextId = 1;
sf::Mutex IdGenerator::mutex;

IdGenerator::IdGenerator() {
    // TODO Auto-generated constructor stub

}

IdGenerator::~IdGenerator() {
    // TODO Auto-generated destructor stub
}
int IdGenerator::GetId(){
    mutex.Lock();
    int id = nextId;
    nextId++;
    mutex.Unlock();
    return id;
}

}
