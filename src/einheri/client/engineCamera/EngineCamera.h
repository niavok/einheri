/*
 * EnginePhysic.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_ENGINECAMERA_H_
#define EIN_ENGINECAMERA_H_

#include <einheri/common/FramerateEngine.h>
#include <einheri/client/ClientGameManager.h>

namespace ein {

class Event;

class EngineCamera : public FramerateEngine{
public:
    EngineCamera(ClientGameManager* manager);
    virtual ~EngineCamera();

    void Apply(const Event& event);
private:
    ClientGameManager* clientManager;
    void frame(EinValue framerate);


};

}

#endif /* EIN_ENGINECAMERA_H_ */
