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
#include <einheri/common/GameManager.h>
#include <einheri/utils/Log.h>

namespace ein {

EngineInput::EngineInput(ClientGameManager* manager) :
    Engine(manager) {
    clientManager = manager;
    renderWindow = NULL;
}

EngineInput::~EngineInput() {
}

void EngineInput::Apply(const Event& event) {
    class EngineInputVisitor: public EventVisitor {
    public:
        EngineInputVisitor(EngineInput* engine) :
            engine(engine) {
        }

        void Visit(const EventWindowCreated& evenWindowCreated) {
            engine->renderWindow = evenWindowCreated.getWindow();
            engine->input = &(engine->renderWindow->GetInput());
            engine->clientManager->GetInputModel()->SetInput(engine->input);
        }
    private:
        EngineInput* engine;
    };
    EngineInputVisitor visitor(this);
    event.accept(visitor);
}

void EngineInput::Frame() {
    if (renderWindow) {
        // Process events
        sf::Event event;
        while (renderWindow->GetEvent(event)) {
            // Close window : exit
            if (event.Type == sf::Event::Closed)
                renderWindow->Close();

            if (event.Type == sf::Event::Resized) {
                clientManager->GetCameraModel()->SetWindowSize(Vector(event.Size.Width, event.Size.Height));
                manager->AddEvent(new EventWindowResized(Vector(event.Size.Width, event.Size.Height)));
            }

            if (event.Type == sf::Event::KeyPressed) {
                manager->AddEvent(new EventKeyPressed(event.Key.Code));
            }

            if (event.Type == sf::Event::KeyReleased) {
                manager->AddEvent(new EventKeyReleased(event.Key.Code));
            }

            if (event.Type == sf::Event::MouseButtonPressed) {
                manager->AddEvent(new EventMouseButtonPressed(event.MouseButton.Button));
            }

            if (event.Type == sf::Event::MouseButtonReleased) {
                manager->AddEvent(new EventMouseButtonReleased(event.MouseButton.Button));
            }
            
        }

    }
}

}
