
#include <einheri/common/GameManager.h>
#include <einheri/common/engineGame/EngineGame.h>
#include <einheri/common/engineGraphic/EngineGraphic.h>

int main()
{

    ein::GameManager gameManager;
    gameManager.AddEngine(new ein::EngineGame(&gameManager));
    gameManager.AddEngine(new ein::EngineGraphic(&gameManager));

    gameManager.Run();

    return 0;
}

