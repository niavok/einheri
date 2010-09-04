/*
 * Engine.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINE_H_
#define EHR_COMMON_ENGINE_H_

namespace ein {

class Event;
class GameManager;

class Engine {
public:
    explicit Engine(GameManager* manager);
    virtual void apply(const Event& event) = 0;
    virtual void frame() = 0;

protected:
    GameManager* manager;
};

}

#endif /* EHR_COMMON_ENGINE_H_ */
