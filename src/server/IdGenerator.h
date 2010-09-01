/*
 * IdGenerator.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef SERVER_IDGENERATOR_H_
#define SERVER_IDGENERATOR_H_

#include <SFML/System.hpp>

namespace einheriServer {


class IdGenerator {
public:
    IdGenerator();
    virtual ~IdGenerator();

    static int GetId();

private:
    static int nextId;
    static sf::Mutex mutex;
};

}

#endif /* IDGENERATOR_H_ */
