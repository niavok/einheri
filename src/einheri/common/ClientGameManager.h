#ifndef EIN_CLIENTGAMEMANAGER_H
#define EIN_CLIENTGAMEMANAGER_H

#include "GameManager.h"

namespace ein {

class ClientGameManager : public GameManager
{
public:
    ClientGameManager();
    virtual ~ClientGameManager();
    
    InputModel* GetInputModel() { return inputModel; }
    CameraModel* GetCameraModel() { return cameraModel; }
    DecorationModel* GetDecorationModel() { return decorationModel; }

private:
    InputModel* inputModel;
    CameraModel* cameraModel;
    DecorationModel* decorationModel;
    
};

}

#endif // EIN_CLIENTGAMEMANAGER_H
