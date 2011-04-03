
#include <einheri/client/ClientGameManager.h>
#include <einheri/common/engineGame/EngineGame.h>
#include <einheri/client/engineGraphic/EngineGraphic.h>
#include <einheri/client/engineSound/EngineSound.h>
#include <einheri/client/engineInput/EngineInput.h>
#include <einheri/common/enginePlayer/EnginePlayer.h>
#include <einheri/common/enginePhysic/EnginePhysic.h>
#include <einheri/common/engineAI/EngineAI.h>
#include <einheri/client/engineCamera/EngineCamera.h>
#include <einheri/client/engineDecoration/EngineDecoration.h>
#include <einheri/client/engineNetworkClient/EngineNetworkClient.h>

int main()
{

    ein::ClientGameManager gameManager;
    gameManager.AddEngine(new ein::EngineGame(&gameManager));

    // Configure graphic engine
    ein::EngineGraphic* graphicEngine = new ein::EngineGraphic(&gameManager);
    graphicEngine->UseFastRender(false);
    gameManager.AddEngine(graphicEngine);
    gameManager.AddEngine(new ein::EngineNetworkClient(&gameManager));
    gameManager.AddEngine(new ein::EngineSound(&gameManager));
    gameManager.AddEngine(new ein::EngineInput(&gameManager));
    gameManager.AddEngine(new ein::EnginePlayer(&gameManager));
    gameManager.AddEngine(new ein::EnginePhysic(&gameManager));
    //gameManager.AddEngine(new ein::EngineAI(&gameManager));
    gameManager.AddEngine(new ein::EngineCamera(&gameManager));
    gameManager.AddEngine(new ein::EngineDecoration(&gameManager));

    gameManager.Run();




    return 0;
}

