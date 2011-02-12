/*
 * BloodRenderer.h
 *
 *  Created on: 9 sept. 2010
 *      Author: fred
 */

#ifndef EIN_BLOODRENDERER_H_
#define EIN_BLOODRENDERER_H_
#include <einheri/common/Decoration.h>
#include <cstdlib>

namespace ein {

class BloodRenderer {
public:
    BloodRenderer();
    virtual ~BloodRenderer();

    void Init();
    void Render(Decoration *decoration);

private:
    uint bloodTextureId;
};

}

#endif /* EIN_BLOODRENDERER_H_ */
