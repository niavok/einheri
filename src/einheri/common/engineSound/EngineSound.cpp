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
#include <einheri/common/event/EventVisitor.h>

using einUtils::FileFinder;

namespace ein {

EngineSound::EngineSound(GameManager* manager) :
    FramerateEngine(manager) {
    music = NULL;
    UseGameTime(false);
    UseSoftFrameRate(true);


    fireSoundBuffer.LoadFromFile(FileFinder::get().file("share/m16.ogg"));
}

EngineSound::~EngineSound() {
    if (music) {
        music->Stop();
        delete music;
    }
    while(!sounds.empty()) {
        sf::Sound* sound = sounds.front();
        if(sound) {
            sound->Stop();
            delete sound;
        }
        sounds.pop_front();
    }

}

void EngineSound::Apply(const Event& event) {
    class EngineSoundVisitor: public EventVisitor {
    public:
        EngineSoundVisitor(EngineSound* engine) :
            engine(engine) {
        }

        void Visit(const EventProjectileAdded& eventProjectileAdded) {
            engine->processEventProjectileAdded(eventProjectileAdded);
        }

    private:
        EngineSound* engine;
    };
    EngineSoundVisitor visitor(this);
    event.accept(visitor);
}

void EngineSound::frame(EinValue) {
    if (!music) {

        // Load a music to play
        music = new sf::Music();

        if (!music->OpenFromFile(FileFinder::get().file("share/Olivier_Militon.-.Apnee.ogg")))
            return;

        LOG("playMusic");
        // Play the music
        music->Play();
    } else if (music->GetStatus() != sf::Music::Playing) {

        delete music;
        music = NULL;
    }

    std::list<sf::Sound*>::iterator it;

    for(it = sounds.begin(); it != sounds.end(); ++it) {
        sf::Sound*& sound = *it;
        if(sound->GetStatus()  != sf::Sound::Playing) {

            delete sound;
            sound = NULL;
        }
    }

    while(sounds.front() == NULL) {
        sounds.pop_front();
    }

}

void EngineSound::processEventProjectileAdded(const EventProjectileAdded& eventProjectileAdded) {
    sf::Sound* sound = new sf::Sound();
    sound->SetBuffer(fireSoundBuffer);
    sound->Play();
    sounds.push_back(sound);
}

}
