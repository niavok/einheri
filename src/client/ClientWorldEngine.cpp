/*
 * ClientWorldEngine.cpp
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */

#include "ClientWorldEngine.h"

ClientWorldEngine::ClientWorldEngine() {
    // TODO Auto-generated constructor stub

}

ClientWorldEngine::~ClientWorldEngine() {
    // TODO Auto-generated destructor stub
}


void InputEngine::Start(){
    running = true;
    Launch();
}

void InputEngine::Stop(){
    running = false;
    Wait();
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
