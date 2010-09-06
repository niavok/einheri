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

    /// @deprecated
    T getX() {
        return x;
    }

    /// @deprecated
    T getY() {
        return y;
    }

    T x;
    T y;
};

////////////////////////////
// Implement operators
////////////////////////////
#define IMPLEMENT_OPERATOR(op)														\
template <typename T>																\
Vect2<T> operator op(const Vect2<T>& left, const Vect2<T>& right){					\
	return Vect2<T>(left.x op right.x, left.x op right.x);							\
}																					\
template <typename T>																\
Vect2<T> operator op(const Vect2<T>& left, T right){								\
	return Vect2<T>(left.x op right, left.x op right);								\
}																					\
template <typename T>																\
Vect2<T> operator op(T left, const Vect2<T>& right){								\
	return Vect2<T>(left op right.x, left op right);								\
}																					\
template <typename T>																\
const Vect2<T>& operator op##=(Vect2<T>& left, const Vect2<T>& right){				\
	left.x op##= right.x; left.y op##= right.y;										\
	return left;																	\
}																					\
template <typename T>																\
const Vect2<T>& operator op##=(Vect2<T>& left, T right){							\
	left.x op##= right; left.y op##= right;											\
	return left;																	\
}

IMPLEMENT_OPERATOR(+)
IMPLEMENT_OPERATOR(-)
IMPLEMENT_OPERATOR(*)
IMPLEMENT_OPERATOR(/)

template <typename T>
bool operator==(const Vect2<T>& left, const Vect2<T>& right){
	return left.x == right.x && left.y == right.y;
}
template <typename T>
bool operator!=(const Vect2<T>& left, const Vect2<T>& right){
	return !(left == right);
}


////////////////////////////
// Create some Types
////////////////////////////

typedef unsigned long EinId;
typedef double EinValue;
typedef Vect2<EinValue> Vector;

}

#endif /* EHR_COMMON_VECT2_H_ */
