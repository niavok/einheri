/*
 * EngineGraphic.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineGraphic.h"
#include <einheri/common/Event.h>

namespace ein {

EngineGraphic::EngineGraphic(GameManager* manager) :
    FramerateEngine(manager) {
    renderWindow = NULL;
}

EngineGraphic::~EngineGraphic() {
}

void EngineGraphic::Apply(const Event& /*event*/) {
}

void EngineGraphic::frame(EinValue frameTime) {
    if (renderWindow == NULL) {
        initWindow();
    } else {
        paint();
    }
}

void EngineGraphic::initWindow() {
    // Create the main window
    sf::WindowSettings Settings;
    Settings.DepthBits = 24; // Request a 24 bits depth buffer
    Settings.StencilBits = 8; // Request a 8 bits stencil buffer
    Settings.AntialiasingLevel = 8; // Request 2 levels of antialiasing
    renderWindow = new sf::RenderWindow(sf::VideoMode(1650, 1080, 32), "Einheri", sf::Style::Close | sf::Style::Resize, Settings);
    renderWindow->ShowMouseCursor(false);
}

void EngineGraphic::paint() {

}

}
