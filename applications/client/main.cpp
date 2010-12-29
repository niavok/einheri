
#include <einheri/common/GameManager.h>
#include <einheri/common/engineGame/EngineGame.h>
#include <einheri/common/engineGraphic/EngineGraphic.h>
#include <einheri/common/engineSound/EngineSound.h>
#include <einheri/common/engineInput/EngineInput.h>
#include <einheri/common/enginePlayer/EnginePlayer.h>
#include <einheri/common/enginePhysic/EnginePhysic.h>
#include <einheri/common/engineScenario/EngineScenario.h>
#include <einheri/common/engineAI/EngineAI.h>
#include <einheri/common/engineCamera/EngineCamera.h>
#include <einheri/common/engineDecoration/EngineDecoration.h>

int main()
{

    ein::GameManager gameManager;
    gameManager.AddEngine(new ein::EngineGame(&gameManager));

    // Configure graphic engine
    ein::EngineGraphic* graphicEngine = new ein::EngineGraphic(&gameManager);
    graphicEngine->UseFastRender(false);
    gameManager.AddEngine(graphicEngine);

    gameManager.AddEngine(new ein::EngineSound(&gameManager));
    gameManager.AddEngine(new ein::EngineInput(&gameManager));
    gameManager.AddEngine(new ein::EnginePlayer(&gameManager));
    gameManager.AddEngine(new ein::EnginePhysic(&gameManager));
    gameManager.AddEngine(new ein::EngineScenario(&gameManager));
    gameManager.AddEngine(new ein::EngineAI(&gameManager));
    gameManager.AddEngine(new ein::EngineCamera(&gameManager));
    gameManager.AddEngine(new ein::EngineDecoration(&gameManager));

    gameManager.Run();




    return 0;
}

