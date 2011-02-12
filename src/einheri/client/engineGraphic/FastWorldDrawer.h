/*
 * WorldDrawer.h
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#ifndef EIN_FASTWORLDDRAWER_H_
#define EIN_FASTWORLDDRAWER_H_
#include <einheri/common/ClientGameManager.h>
#include "GenericWorldDrawer.h"
#include "BloodRenderer.h"

namespace ein {

class FastWorldDrawer : public GenericWorldDrawer{
public:
    FastWorldDrawer(ClientGameManager * manager);
    virtual ~FastWorldDrawer();

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
    uint marineTextureId;

    BloodRenderer bloodRenderer;
};

}

#endif /* EIN_FASTWORLDDRAWER_H_ */
