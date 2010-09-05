/*
 * EngineInput.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineInput.h"
#include <einheri/common/Event.h>
#include <einheri/common/event/EventVisitor.h>
#include "einheri/common/event/EventWindowCreated.h"

namespace ein {

EngineInput::EngineInput(GameManager* manager) : Engine(manager){
    renderWindow = NULL;
}

EngineInput::~EngineInput() {
}

void EngineInput::Apply(const Event& event) {
    class EngineInputVisitor : public EventVisitor
        {
        public:
            EngineInputVisitor(EngineInput* engine):engine(engine){}

            void Visit(const EventWindowCreated& evenWindowCreated)
            {
                engine->renderWindow = evenWindowCreated.getWindow();
            }
        private:
            EngineInput* engine;
        };
        EngineInputVisitor visitor(this);
        event.accept(visitor);
}

void EngineInput::Frame() {
    if(renderWindow) {
        // Process events
        sf::Event event;
        while (renderWindow->GetEvent(event)) {
            // Close window : exit
            if (event.Type == sf::Event::Closed)
                renderWindow->Close();

            if (event.Type == sf::Event::Resized)
                //graphicEngine.Resize(event.Size.Width, event.Size.Height);

            if (event.Type == sf::Event::KeyPressed || event.Type == sf::Event::MouseMoved || event.Type == sf::Event::MouseButtonPressed || event.Type == sf::Event::MouseButtonReleased) {
                //inputEngine.PushEvent(event);
            }

        }
    }

}

}
