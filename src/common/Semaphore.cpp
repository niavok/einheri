/*
 * Semaphore.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include "Semaphore.h"

Semaphore::Semaphore() {
    tokenCount = 0;
    waitMutex.Lock();
}

Semaphore::~Semaphore() {
 }


void Semaphore::set() {
    transactionMutex.Lock();

    tokenCount++;
    waitMutex.Unlock();

    transactionMutex.Unlock();
}

bool Semaphore::get(bool wait) {
    bool result = true;

    if(wait){
        waitMutex.Lock();
        transactionMutex.Lock();
        tokenCount--;
        if(tokenCount > 0) {
            waitMutex.Unlock();
        }
        transactionMutex.Unlock();

    }else {

        transactionMutex.Lock();

        if(tokenCount > 0) {
            tokenCount--;
            if(tokenCount == 0) {
                waitMutex.Lock();
            }
        }else {
            result = false;
        }
        transactionMutex.Unlock();
    }

    return result;
}

int Semaphore::count() {
    return tokenCount;
}
