/*
 * Semaphore.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

#include <SFML/System.hpp>


class Semaphore {
public:
    Semaphore();
    virtual ~Semaphore();

    void set();

    bool get(bool wait = true);

    int count();

private:
    sf::Mutex transactionMutex;
    sf::Mutex waitMutex;
    int tokenCount;

};

#endif /* SEMAPHORE_H_ */
