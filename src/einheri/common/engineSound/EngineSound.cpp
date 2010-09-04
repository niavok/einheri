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
    playingMusic = false;
}

EngineSound::~EngineSound() {
}

void EngineSound::Apply(const Event& /*event*/) {
}

void EngineSound::Frame() {
    if(!playingMusic) {
        playingMusic = true;
    // Load a music to play
         sf::Music Music;
         if (!Music.OpenFromFile(FileFinder::get().file("share/Olivier_Militon.-.Apnee.ogg")))
             return;

         LOG("playMusic");
         // Play the music
         Music.Play();
    }
}

}
