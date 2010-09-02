/*
 * Application.cpp
 *
 *  Created on: 22 août 2010
 *      Author: fred
 */

#include "Application.h"

#include <Utils/FileFinder.h>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>

namespace einheri {

Application::Application():
    clientWorldEngine(this),
    gameEngine(this),
    graphicEngine(this),
    inputEngine(this),
    networkEngine(this){
    app = NULL;

}

Application::~Application(){
    delete app;
}

void Application::Run() {

     // Create the main window
    sf::WindowSettings Settings;
    Settings.DepthBits         = 24; // Request a 24 bits depth buffer
    Settings.StencilBits       = 8;  // Request a 8 bits stencil buffer
    Settings.AntialiasingLevel = 8;  // Request 2 levels of antialiasing
    app = new sf::RenderWindow(sf::VideoMode(1650, 1080, 32), "Einheri", sf::Style::Close|sf::Style::Resize, Settings);

    graphicEngine.Init();



    using einUtils::FileFinder;

     // Load a sprite to display
     sf::Image Image;
     if (!Image.LoadFromFile(FileFinder::get().file("share/cute_image.jpg")))
         return;
     sf::Sprite Sprite(Image);

     // Create a graphical string to display
     sf::Font Arial;
     if (!Arial.LoadFromFile(FileFinder::get().file("share/arial.ttf")))
         return;
     sf::String title("Einheri", Arial, 16);
     sf::String fps("0 fps", Arial, 16);
     fps.SetPosition(0,20);


     // Load a music to play
     sf::Music Music;
     if (!Music.OpenFromFile(FileFinder::get().file("share/Olivier_Militon.-.Apnee.ogg")))
         return;

     // Play the music
     Music.Play();

     std::cout<<"startGraphicEngine"<<std::endl;
     std::cout<<"main loop start"<<std::endl;

     app->PreserveOpenGLStates(true);

     sf::Clock framerateClock;
     int fpsCount = 0;

     clientWorldEngine.Start();
     gameEngine.Start();

     inputEngine.Start();
     networkEngine.Start();

     // Start the game loop
     while (app->IsOpened())
     {
         // Process events
         sf::Event event;
         while (app->GetEvent(event))
         {
             //std::cout<<"main event loop"<<std::endl;
             // Close window : exit
             if (event.Type == sf::Event::Closed)
                 app->Close();

             if (event.Type == sf::Event::Resized)
                 graphicEngine.Resize(event.Size.Width, event.Size.Height);

             if (event.Type == sf::Event::KeyPressed ||
                 event.Type == sf::Event::MouseMoved) {
                 inputEngine.PushEvent(event);
             }

         }


         if(graphicEngine.Paint()){
             fpsCount++;
             app->Draw(title);

             if(framerateClock.GetElapsedTime() > 1) {
                  float framerate = fpsCount/ framerateClock.GetElapsedTime();
                  framerateClock.Reset();
                  fpsCount = 0;
                  std::ostringstream oss;
                  oss.precision(1);
                  oss.setf(std::ios::fixed);
                  oss << framerate;
                  fps.SetText(oss.str() + " fps");
                  fps.SetPosition(0,20);
              }

             app->Draw(fps);


             app->Display();

         }




         //Max cpu usage pass for 100% to 0%
         sf::Sleep(0.0001f);





     }

     networkEngine.Stop();

     inputEngine.Stop();
     gameEngine.Stop();

     clientWorldEngine.Stop();

     std::cout<<"main loop exit"<<std::endl;




     return;

}

}
