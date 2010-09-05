/*
 * EnginePhysic.cpp
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#include "EngineSound.h"
#include <einheri/common/Event.h>
#include <SFML/Audio.hpp>
#include <einheri/utils/FileFinder.h>
#include <einheri/utils/Log.h>

using einUtils::FileFinder;

namespace ein {

EngineSound::EngineSound(GameManager* manager) : Engine(manager){
    music = NULL;
}

EngineSound::~EngineSound() {
    if(music) {
        music->Stop();
        delete music;
    }
}

void EngineSound::Apply(const Event& /*event*/) {
}

void EngineSound::Frame() {
    if(!music) {

    // Load a music to play
         music = new sf::Music();
         //if (!Music.OpenFromFile(FileFinder::get().file("share/Olivier_Militon.-.Apnee.ogg")))

         if (!music->OpenFromFile("/home/fred/projets/einheri/files/share/Olivier_Militon.-.Apnee.ogg"))
             return;

         LOG("playMusic");
         // Play the music
         music->Play();
    } else if(music->GetStatus() != sf::Music::Playing) {

        delete music;
        music = NULL;
    }

}

}
