#include "ClientGameManager.h"


namespace ein {
ClientGameManager::ClientGameManager() {
    inputModel = new InputModel();
    cameraModel = new CameraModel();
    decorationModel = new DecorationModel();
}

ClientGameManager::~ClientGameManager() {
    delete cameraModel;
    delete inputModel;
    delete decorationModel;
}


}
