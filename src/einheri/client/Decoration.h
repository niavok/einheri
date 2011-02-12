/*
 * Projectile.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef EIN_DECORATION_H_
#define EIN_DECORATION_H_
#include <string>
#include <einheri/common/Vect2.h>

namespace ein {

class Decoration {
public:
    enum DecorationType {
        BLOOD,
        CORPSE
    };

public:
    Decoration(DecorationType type): type(type) {};
    virtual ~Decoration();

    void SetPosition(Vector newPosition) { position = newPosition; }
    void SetBeginTime(EinValue newBeginTime) { beginTime = newBeginTime; }
    void SetEndTime(EinValue newEndTime) { endTime = newEndTime; }
    void SetGraphic(EinValue newGraphic) { graphic = newGraphic; }
    void SetAngle(EinValue newAngle) { angle = newAngle; }

    Vector GetPosition( ) { return position; }
    EinValue GetBeginTime( ) { return beginTime; }
    EinValue GetEndTime( ) { return endTime; }
    EinValue GetGraphic( ) { return graphic; }
    EinValue GetAngle( ) { return angle; }

private:
    Vector position;
    EinValue beginTime;
    EinValue endTime;
    DecorationType type;
    EinValue graphic;
    EinValue angle;
};

}

#endif /* EIN_DECORATION_H_ */
