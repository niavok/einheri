#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GraphicEngine.h"
#include "InputEngine.h"
#include <iostream>
#include <sstream>

 int main()
 {

     // Create the main window
    sf::WindowSettings Settings;
    Settings.DepthBits         = 24; // Request a 24 bits depth buffer
    Settings.StencilBits       = 8;  // Request a 8 bits stencil buffer
    Settings.AntialiasingLevel = 8;  // Request 2 levels of antialiasing
    sf::RenderWindow app(sf::VideoMode(1650, 1080, 32), "Einheri", sf::Style::Close, Settings);

    einheri::GraphicEngine graphicEngine;

    graphicEngine.Init();

    einheri::InputEngine inputEngine;


     // Load a sprite to display
     sf::Image Image;
     if (!Image.LoadFromFile("data/cute_image.jpg"))
         return EXIT_FAILURE;
     sf::Sprite Sprite(Image);
 
     // Create a graphical string to display
     sf::Font Arial;
     if (!Arial.LoadFromFile("data/arial.ttf"))
         return EXIT_FAILURE;
     sf::String title("Einheri", Arial, 16);
     sf::String fps("0 fps", Arial, 16);
     fps.SetPosition(0,20);
 
     // Load a music to play
     sf::Music Music;
     if (!Music.OpenFromFile("data/Olivier_Militon.-.Apnee.ogg"))
         return EXIT_FAILURE;

     // Play the music
     Music.Play();
 
     std::cout<<"startGraphicEngine"<<std::endl;
     std::cout<<"main loop start"<<std::endl;

     app.PreserveOpenGLStates(true);

     sf::Clock framerateClock;
     int fpsCount = 0;

     inputEngine.Start();

     // Start the game loop
     while (app.IsOpened())
     {
         // Process events
         sf::Event event;
         while (app.GetEvent(event))
         {

             // Close window : exit
             if (event.Type == sf::Event::Closed)
                 app.Close();

             if (event.Type == sf::Event::Resized)
                 graphicEngine.Resize(event.Size.Width, event.Size.Height);

             if (event.Type == sf::Event::KeyPressed ||
                 event.Type == sf::Event::MouseMoved) {
                 inputEngine.PushEvent(event);
             }

         }

         graphicEngine.Paint();
 
         app.Draw(title);

         fpsCount++;

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

         app.Draw(fps);

         app.Display();


     }

     inputEngine.Stop();
     std::cout<<"main loop exit"<<std::endl;




     return EXIT_SUCCESS;
 }

