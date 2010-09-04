/*
 * Vect2.h
 *
 *  Created on: 2 sept. 2010
 *      Author: fred
 */

#ifndef EHR_COMMON_VECT2_H_
#define EHR_COMMON_VECT2_H_

namespace ein {

template<typename T>
class Vect2 {
public:
    Vect2() :
        x(0), y(0) {
    }
    Vect2(T x, T y) {
        this->x = x;
        this->y = y;
    }
    virtual ~Vect2() {
    }

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

typedef unsigned long EinId;
typedef double EinValue;
typedef Vect2<EinValue> Vector;

}

#endif /* EHR_COMMON_VECT2_H_ */
