/*
 * EngineGraphic.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_ENGINEGRAPHIC_H_
#define EHR_COMMON_ENGINEGRAPHIC_H_

#include <einheri/common/Engine.h>
#include "einheri/common/FramerateEngine.h"
#include <SFML/Graphics.hpp>
#include "GenericWorldDrawer.h"

namespace ein {

class Event;

class EngineGraphic : public FramerateEngine {
public:
    EngineGraphic(GameManager* manager);
    virtual ~EngineGraphic();

    void Apply(const Event& event);

    /**
     * Configure the graphic engine to use a debug renderer working on very slow
     * gpu drivers (as open source drivers)
     */
    void UseFastRender(bool fastRender);

private:
    void frame(EinValue frameTime);

    void initWindow();
    void initGlContext();

    void paint();

private :

    sf::RenderWindow *renderWindow;
    GenericWorldDrawer * worldDrawer;

    sf::Clock framerateClock;
    sf::String title;
    sf::String fps;
    sf::Font font;
    int fpsCount;
};

}

#endif /* EHR_COMMON_ENGINEGRAPHIC_H_ */
