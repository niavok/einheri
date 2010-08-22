/*
 * GraphicEngine.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef GRAPHICENGINE_H_
#define GRAPHICENGINE_H_


#include <SFML/Window.hpp>

namespace einheri {

class ClientWorldModel;
class Application;


class GraphicEngine{
public:
    GraphicEngine(Application *application);
    virtual ~GraphicEngine();

    void Init();
    bool Paint();
    void Resize(int width, int height);

private:
    sf::Clock clock;
    Application *application;
    float lastFrameClock;
    float frameDuration;

    ClientWorldModel * modelToDraw;

    void clearView();

    void configureCamera();

    void paintGround();
    void paintCorpses();
    void paintDecorations();
    void paintHeroes();
    void paintProjectiles();
    void paintEffects();

};

}

#endif /* GRAPHICENGINE_H_ */
