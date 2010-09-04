/*
 * Lock.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_SCOPEDLOCK_H_
#define EIN_SCOPEDLOCK_H_

#include <SFML/System/Mutex.hpp>

namespace einUtils {

class ScopedLock {
public:
    ScopedLock(sf::Mutex &mutex):mutex(mutex) {
        mutex.Lock();
    }

    ~ScopedLock() {
        mutex.Unlock();
    }
private:
    sf::Mutex &mutex;
};

}  // namespace einUtils

#endif /* EIN_SCOPEDLOCK_H_ */
