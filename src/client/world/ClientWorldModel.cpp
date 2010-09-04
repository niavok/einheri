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
/*
void ClientWorldModel::Copy(ClientWorldModel *sourceModel) {

    //Copy monsters
    {
        std::map<int, Monster *>::const_iterator it;

        for(it = sourceModel->GetMonsters().begin(); it != sourceModel->GetMonsters().end(); ++it) {
            monsters[it->first] = it->second;
        }
    }

    //Copy heroes
    {
        std::map<int, Hero *>::const_iterator it;

        for(it = sourceModel->GetHeroes().begin(); it != sourceModel->GetHeroes().end(); ++it) {
            heroes[it->first] = it->second;
        }
    }

    //heroes = sourceModel->heroes;
    //monsters = sourceModel->monsters;

}*/

void ClientWorldModel::AddMonster(Monster *monster){
    if(!monster) {
        std::cerr<<"Error : null monster"<<std::endl;
    }
    monsters[monster->id] = monster;
}

void ClientWorldModel::AddHero(Hero *hero){
    if(!hero) {
        std::cerr<<"Error : null hero"<<std::endl;
    }
    heroes[hero->id] = hero;
}

void ClientWorldModel::AddProjectile(Projectile *projectile){
    if(!projectile) {
        std::cerr<<"Error : null projectile"<<std::endl;
    }
    projectiles[projectile->id] = projectile;
}

const std::map<int, Monster *> &ClientWorldModel::GetMonsters(){
    return monsters;
}

const std::map<int, Hero *> &ClientWorldModel::GetHeroes(){
    return heroes;
}


const std::map<int, Projectile *> &ClientWorldModel::GetProjectiles(){
    return projectiles;
}

}
