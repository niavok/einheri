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
    input->IsKeyDown(sf::Key::Q);
}

bool InputEngine::IsMoveRight() {
    input->IsKeyDown(sf::Key::D);
}

bool InputEngine::IsMoveUp() {
    input->IsKeyDown(sf::Key::Z);
}

bool InputEngine::IsMoveDown() {
    input->IsKeyDown(sf::Key::S);
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
                std::cout<<"Key Pressed"<<std::endl;
        }

    }
    std::cout<<"InputEngine stopped"<<std::endl;
}

}
