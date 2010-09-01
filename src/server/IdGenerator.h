/*
 * IdGenerator.h
 *
 *  Created on: 29 août 2010
 *      Author: fred
 */

#ifndef SERVER_IDGENERATOR_H_
#define SERVER_IDGENERATOR_H_

namespace einheriServer {

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
