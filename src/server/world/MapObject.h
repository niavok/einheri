/*
 * Monster.h
 *
 *  Created on: 21 août 2010
 *      Author: fred
 */

#ifndef SERVER_MAP_OBJECT_H_
#define SERVER_MAP_OBJECT_H_

namespace einheriServer {

class MapObject {
public:
    MapObject();
    virtual ~MapObject();

    void GenerateId();

    int id;

    double positionX;
    double positionY;
    double speedX;
    double speedY;
    double angle;

};

}

#endif /* SERVER_MAP_OBJECT_H_ */
