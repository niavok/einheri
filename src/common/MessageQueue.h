/*
 * MessageQueue.h
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */

#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_

#include "Semaphore.h"
#include <queue>

template<typename T>
class MessageQueue {
public:
    MessageQueue(){}
    virtual ~MessageQueue(){}

    void PushMessage(T message) {
        messageQueue.push(message);
        messageSemaphore.set();
    }
    T PopMessage() {
        messageSemaphore.get();
        T message = messageQueue.front();
        messageQueue.pop();
        return message;
    }

private:

    Semaphore messageSemaphore;
    std::queue<T> messageQueue;

};

#endif /* MESSAGEQUEUE_H_ */
