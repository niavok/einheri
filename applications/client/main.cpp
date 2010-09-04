
#include <einheri/common/GameManager.h>
#include <einheri/common/engineGame/EngineGame.h>

int main()
{

    ein::GameManager gameManager;
    gameManager.AddEngine(new ein::EngineGame(&gameManager));

    gameManager.Run();

    return 0;
}

