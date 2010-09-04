/*
 * Monster.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef CLIENT_MAP_OBJECT_H_
#define CLIENT_MAP_OBJECT_H_

namespace einheri{

class MapObject {
public:
    MapObject();
    virtual ~MapObject();

    int id;

    double positionX;
    double positionY;
    double speedX;
    double speedY;
    double angle;

};

}

#endif /* SERVER_MAP_OBJECT_H_ */
