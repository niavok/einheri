/*
 * ClientWorldModel.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "ClientWorldModel.h"


namespace einheri {


ClientWorldModel::ClientWorldModel() {
    // TODO Auto-generated constructor stub

}

ClientWorldModel::~ClientWorldModel() {
    // TODO Auto-generated destructor stub
}
void ClientWorldModel::Lock(){
    lock.Lock();
}

void ClientWorldModel::Unlock() {
    lock.Unlock();
}

void ClientWorldModel::Copy(ClientWorldModel *sourceModel) {
    heroes = sourceModel->heroes;
}


}
