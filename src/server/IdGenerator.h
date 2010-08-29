/*
 * IdGenerator.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef IDGENERATOR_H_
#define IDGENERATOR_H_

namespace einheri {

class IdGenerator {
public:
    IdGenerator();
    virtual ~IdGenerator();

    static int GetId();

private:
    static int nextId;

};

}

#endif /* IDGENERATOR_H_ */
