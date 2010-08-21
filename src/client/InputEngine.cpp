/*
 * InputEngine.cpp
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#include <iostream>
#include "InputEngine.h"

namespace einheri {

InputEngine::InputEngine() {

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

//Private

void InputEngine::Run(){
    std::cout<<"InputEngine started"<<std::endl;
    while(running) {
        sf::Event event = eventQueue.PopMessage();

        if(event.Type == sf::Event::MouseMoved) {
            std::cout<<"Mouse moved "<<event.MouseMove.X<<" "<<event.MouseMove.Y<<std::endl;
        }

        if(event.Type == sf::Event::KeyPressed) {
                std::cout<<"Key Pressed"<<std::endl;
        }

    }
    std::cout<<"InputEngine stopped"<<std::endl;
}

}
