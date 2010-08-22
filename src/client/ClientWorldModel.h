/*
 * ClientWorldModel.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef CLIENTWORLDMODEL_H_
#define CLIENTWORLDMODEL_H_

#include <SFML/System.hpp>
#include "Heroes.h"

namespace einheri {

class ClientWorldModel {
public:
    ClientWorldModel();
    virtual ~ClientWorldModel();

    void Lock();
    void Unlock();

    void Copy(ClientWorldModel *sourceModel);

    Heroes heroes;

private:
    sf::Mutex lock;

};

}

#endif /* CLIENTWORLDMODEL_H_ */
