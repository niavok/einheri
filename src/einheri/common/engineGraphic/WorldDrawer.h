/*
 * WorldDrawer.h
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#ifndef EIN_WORLDDRAWER_H_
#define EIN_WORLDDRAWER_H_
#include <einheri/common/GameManager.h>

namespace ein {

class WorldDrawer {
public:
    WorldDrawer(GameManager * manager);
    virtual ~WorldDrawer();

    void Init();
    void Draw();

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
    GameManager *manager;
    int monsterListIndex;

};

}

#endif /* EIN_WORLDDRAWER_H_ */
