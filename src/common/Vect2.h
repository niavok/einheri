/*
 * Vect2.h
 *
 *  Created on: 2 sept. 2010
 *      Author: fred
 */

#ifndef VECT2_H_
#define VECT2_H_

namespace einheri {

template<typename T>
class Vect2 {
public:
    Vect2(T x, T y){
        this->x = x;
        this->y = y;
    }
    virtual ~Vect2(){}

    T getX() {
        return x;
    }

    T getY() {
        return y;
    }

private:

    T x;
    T y;

};

}

#endif /* VECT2_H_ */
