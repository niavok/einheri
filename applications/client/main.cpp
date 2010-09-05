
#include <einheri/common/GameManager.h>
#include <einheri/common/engineGame/EngineGame.h>
#include <einheri/common/engineGraphic/EngineGraphic.h>
#include <einheri/common/engineSound/EngineSound.h>
#include <einheri/common/engineInput/EngineInput.h>

int main()
{

    ein::GameManager gameManager;
    gameManager.AddEngine(new ein::EngineGame(&gameManager));
    gameManager.AddEngine(new ein::EngineGraphic(&gameManager));
    gameManager.AddEngine(new ein::EngineSound(&gameManager));
    gameManager.AddEngine(new ein::EngineInput(&gameManager));

    gameManager.Run();

    return 0;
}

