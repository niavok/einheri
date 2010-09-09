/*
 * BloodRenderer.cpp
 *
 *  Created on: 9 sept. 2010
 *      Author: fred
 */

#include "BloodRenderer.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <einheri/utils/FileFinder.h>
#include <einheri/utils/Log.h>
#include "einheri/common/Timer.h"

using einUtils::FileFinder;

namespace ein {

BloodRenderer::BloodRenderer() {
    // TODO Auto-generated constructor stub

}

BloodRenderer::~BloodRenderer() {
    // TODO Auto-generated destructor stub
}

void BloodRenderer::Init() {
    sf::Image bloodImage;
    if (!bloodImage.LoadFromFile(FileFinder::get().file("share/blood1.png"))) {
        LOG("Fail to load share/blood1.png");
        return;
    }


        glGenTextures(1, &bloodTextureId);
        glBindTexture(GL_TEXTURE_2D, bloodTextureId);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, bloodImage.GetWidth(), bloodImage.GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE, bloodImage.GetPixelsPtr());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

}

void BloodRenderer::Render(Decoration *decoration) {

    EinValue time = Timer::get().GetGameTime();
    float effectDuration = decoration->GetEndTime() - decoration->GetBeginTime();
    float effectAge = time - decoration->GetBeginTime();

    float size = 0.1 + 0.9  * 3* effectAge  / effectDuration;
    if(size > 1) {
        size = 1;
    }
    float texOffset = 1;

    float opacity = 3.f - 3* effectAge  / effectDuration;

    if(opacity > 1) {
        opacity = 1;
    }


    glPushMatrix();
    glTranslated(decoration->GetPosition().x, decoration->GetPosition().y, 0);
    glRotatef(decoration->GetAngle() * 180 / M_PI, 0, 0, 1);


    glBindTexture( GL_TEXTURE_2D, bloodTextureId );
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
    glColor4f(opacity, 1.f, opacity, opacity);
    glTexCoord2f(texOffset, 0);
    glVertex3f(-size, -size, 0.f);
    glTexCoord2f(0, 0);
    glVertex3f(size, -size, 0.f);
    glTexCoord2f(0, texOffset);
    glVertex3f(size, size, 0.f);
    glTexCoord2f(texOffset, texOffset);
    glVertex3f(-size, size, 0.f);

    glEnd();

    glDisable(GL_TEXTURE_2D);


    glPopMatrix();
}

}
