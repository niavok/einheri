/*
 * InputEngine.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include <iostream>
#include "InputEngine.h"
#include "Application.h"


namespace einheri {

InputEngine::InputEngine(Application *application) {
    app = application;

}

InputEngine::~InputEngine() {
    // TODO Auto-generated destructor stub
}




void InputEngine::Start(){
    running = true;
    Launch();
}

void InputEngine::Stop(){
    running = false;
    sf::Event endEvent;
    endEvent.Type = sf::Event::Closed;
    eventQueue.PushMessage(endEvent);
    Wait();
}

void InputEngine::PushEvent(sf::Event event){
    eventQueue.PushMessage(event);
}

bool InputEngine::IsMoveLeft() {
    return input->IsKeyDown(sf::Key::Q);
}

bool InputEngine::IsMoveRight() {
    return input->IsKeyDown(sf::Key::D);
}

bool InputEngine::IsMoveUp() {
    return input->IsKeyDown(sf::Key::Z);
}

bool InputEngine::IsMoveDown() {
    return input->IsKeyDown(sf::Key::S);
}


Vect2<int> InputEngine::GetMouse() {
    return Vect2<int>(input->GetMouseX(), input->GetMouseY());
}

//Private

void InputEngine::Run(){
    std::cout<<"InputEngine started"<<std::endl;

    input = &(app->app->GetInput());


    while(running) {
        sf::Event event = eventQueue.PopMessage();

        if(event.Type == sf::Event::MouseMoved) {
            //std::cout<<"Mouse moved "<<event.MouseMove.X<<" "<<event.MouseMove.Y<<std::endl;
        }

        if(event.Type == sf::Event::KeyPressed) {
                //std::cout<<"Key Pressed"<<std::endl;
        }

        if(event.Type == sf::Event::MouseButtonPressed) {
            std::cout<<"Click"<<std::endl;
            if(event.MouseButton.Button == sf::Mouse::Left) {
                std::cout<<"Click left"<<std::endl;
                Vect2<double> cursor = app->graphicEngine.Pick(GetMouse());
                app->networkEngine.UseMainAction(app->gameEngine.localPlayer.heroId, cursor);
            }
        }

    }
    std::cout<<"InputEngine stopped"<<std::endl;
}

}
