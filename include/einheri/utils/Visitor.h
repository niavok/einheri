/*
 * Visitor.h
 *
 *  Created on: 4 sept. 2010
 *      Author: fred
 */

#ifndef VISITOR_H_
#define VISITOR_H_

namespace einUtils {

template <class T, class T_Visitor>
struct Visitable
{
    void accept(T_Visitor& visitor)
    {
        visitor.visit(static_cast<T>(this) );
    }
};

}  // namespace ehrUtils

#endif /* VISITOR_H_ */
