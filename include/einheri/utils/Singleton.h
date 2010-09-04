/*
 * Copyright or © or Copr. INRIA, ECP Digiplant project 
 * contributor(s) :
 * Thomas Guyard (thomas[dot]guyard[at]gmail[dot]com)
 * 
 * This software is a computer program whose purpose is to edit 
 * XML files using a generated interface based on XMLShema file.
 * 
 * This software is governed by the CeCILL-C license under French law and
 * abiding by the rules of distribution of free software.  You can  use, 
 * modify and/ or redistribute the software under the terms of the CeCILL-C
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info". 
 * 
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability. 
 * 
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or 
 * data to be ensured and,  more generally, to use and operate it in the 
 * same conditions as regards security. 
 * 
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL-C license and that you accept its terms.
 */
/////////////////////////////////////////////////////////////////////////////
//
// Singleton - modèle Singleton applicable à n'importe quelle classe.
//
/////////////////////////////////////////////////////////////////////////////
#ifndef TRIVIAL_SINGLETON_H_
#define TRIVIAL_SINGLETON_H_

#include <SFML/System/Mutex.hpp>

#define EIN_SINGLETON(myClass) friend class     einUtils::Singleton<myClass>

namespace einUtils {

/**
 * @brief a singleton template.
 * example:
 *
 * class MaClass : public einUtils::Singleton<MaClass>
 * {
 *      EIN_SINGLETON(MaClass);
 *      MaClass();
 *  public:
 *      void do();
 *      ...
 * };
 * MaClass::get().do();
 *
 */
template <class T>
class Singleton : private sf::NonCopyable
{
public:
    static T& get()
    {
		createLock.Lock();
        if(t == NULL)
        {
            t = new T();
        }
		createLock.Unlock();
        return *t;
    }

    /// @brief delete and create the instance.
    static void init() // never throws
    {
		createLock.Lock();
		delete t;
        t = new T();
		createLock.Unlock();
    }

protected:
    virtual ~Singleton() {}
    Singleton() {}

private:
     static T* t;
	 static sf::Mutex createLock;
};

template<class T> sf::Mutex einUtils::Singleton<T>::createLock;
template<class T> T* einUtils::Singleton<T>::t(NULL);

}  // namespace einUtils

#endif
