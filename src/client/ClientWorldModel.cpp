/*
 * ClientWorldModel.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "ClientWorldModel.h"
#include <iostream>

namespace einheri {


ClientWorldModel::ClientWorldModel() {
    // TODO Auto-generated constructor stub

}

ClientWorldModel::~ClientWorldModel() {
    // TODO Auto-generated destructor stub
}
void ClientWorldModel::Lock(){
    //std::cout<<"ClientWorldModel : want lock "<<this<<std::endl;
    lock.Lock();
    //std::cout<<"ClientWorldModel : lock "<<this<<std::endl;
}

void ClientWorldModel::Unlock() {
    //std::cout<<"ClientWorldModel : unlock "<<this<<std::endl;
    lock.Unlock();
}

void ClientWorldModel::Copy(ClientWorldModel *sourceModel) {
    heroes = sourceModel->heroes;
    monsters = sourceModel->monsters;

}

void ClientWorldModel::AddMonster(Monster *monster){
    if(!monster) {
        std::cerr<<"Error : null monster"<<std::endl;
    }
    monsters[monster->id] = monster;
}

const std::map<int, Monster *> &ClientWorldModel::GetMonsters(){
    return monsters;
}

const std::map<int, Hero *> &ClientWorldModel::GetHeroes(){
    return heroes;
}


}
