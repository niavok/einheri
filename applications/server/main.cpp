
#include <einheri/common/GameManager.h>
#include <einheri/common/engineGame/EngineGame.h>
#include <einheri/common/enginePhysic/EnginePhysic.h>
#include <einheri/common/engineScenario/EngineScenario.h>
#include <einheri/common/engineAI/EngineAI.h>
#include <einheri/common/engineNetwork/EngineNetworkServer.h>

int main()
{

    ein::GameManager gameManager;
    //gameManager.AddEngine(new ein::EngineGame(&gameManager));

    
    //gameManager.AddEngine(new ein::EngineNetworkServer(&gameManager));
    //gameManager.AddEngine(new ein::EnginePhysic(&gameManager));
    //gameManager.AddEngine(new ein::EngineScenario(&gameManager));
    //gameManager.AddEngine(new ein::EngineAI(&gameManager));
    
    gameManager.Run();




    return 0;
}

