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

class GraphicEngine{
public:
    GraphicEngine();
    virtual ~GraphicEngine();

    void Init();
    void Paint();
    void Resize(int width, int height);

private:
    sf::Clock clock;

};

}

#endif /* GRAPHICENGINE_H_ */
