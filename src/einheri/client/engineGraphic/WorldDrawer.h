/*
 * WorldDrawer.h
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#ifndef EIN_WORLDDRAWER_H_
#define EIN_WORLDDRAWER_H_
#include <einheri/client/ClientGameManager.h>
#include "GenericWorldDrawer.h"
#include "BloodRenderer.h"

namespace ein {

class WorldDrawer : public GenericWorldDrawer {
public:
    WorldDrawer(ClientGameManager * manager);
    virtual ~WorldDrawer();

    void Init();
    void Draw();
    void Resize(Vector newWindowSize);

private:
    void clearView();

    void configureCamera();

    void paintGround();
    void paintCorpses();
    void paintDecorations();
    void paintMonsters();
    void paintHeroes();
    void paintProjectiles();
    void paintEffects();
    void paintCursor();

private:
    ClientGameManager *manager;
    int monsterListIndex;
    Vector windowSize;
    uint groundTextureId;
    uint marineTextureId;
    uint ghostTextureId;

    BloodRenderer bloodRenderer;
};

}

#endif /* EIN_WORLDDRAWER_H_ */
