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
/**
 * @file TrivialLogger.h
 * @brief
 * @author Thomas Guyard
 */

#ifndef TRIVIALLOGGER_H_
#define TRIVIALLOGGER_H_

#if !defined(CLEAN_LOG)

#include "Singleton.h"
#include <ostream>
#include <memory>
#include <fstream>
#include <iostream>

namespace einUtils {
namespace detail
{


/**
 * This class is used to print some logging messages.
 * To use it you have to use some defined macros.
 * In fact the objective is to be able to totally desactivate during the compilation the logging messages.
 * There is several ways to log some messages: see LOG_D, LOG_I, LOG_W, LOG_E, LOG_CONSTRUCTOR, LOG_DESTRUCTOR.
 */
class logger : public Singleton<logger>
{
    ELS_SINGLETON(logger);
    /**
     * @brief construct a logger on cout by default.
     * define NLOG to log to /dev/null
     * define ETLOG to log on std::cerr
     * define FTLOG to log to a file named _logger.out
     */
    logger()
    {
        isActive = true;
        outstream = NULL;

        #if defined(NLOG)
        outstream = new NullStream;

        #elif defined (ETLOG)
        outstream = &std::cerr;

        #elif defined (FTLOG)
        outstream = new std::ofstream ( "_logger.out" );
        // here is a place for user defined output stream
        // and compiler flag
        #else
        outstream = &std::cout;
        #endif
    }
public:
    ~logger()
    {
        #if defined(NLOG)
        delete outstream;
        #elif defined (ETLOG)
        #elif defined (FTLOG)
        static_cast<std::ofstream*> (outstream)->close();
        delete outstream;
        // here is a place for user defined output stream
        // and compiler flag
        #else
        #endif
    }
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    void put_debug_info(T1 const & type, T2 const & file, T3 const & line, T4 const & message , T5 const & variable, T6 const & value)
    {
        if (isActive)
        {
            ///////////////////////////////////////////////////////////////////////////////////////////
            // WARNING : this to have shorter file name. This only works on the digiplant project !!!//
            std::string shortFile(file);                                                             //
            if ( shortFile.find("Sources") < shortFile.size())                                       //
            {                                                                                        //
                shortFile.erase(0, shortFile.find("Sources") + 8);                                   //
            }                                                                                        //
            // This should be removed or changed if the file path change !!                          //
            ///////////////////////////////////////////////////////////////////////////////////////////

            *(outstream) << type  <<" : "<< shortFile <<" (" << line << ") : " << message << " : " << variable << " = " << value<< std::endl;
        }
    }
    std::ostream* log(){return outstream;}

    void On(){isActive = true;};
    void Off(){isActive = false;};
    bool IsActive(){return isActive;};

private:
    bool isActive;
    std::ostream * outstream;
    std::auto_ptr<std::ostream> outstream_helper_ptr;

};
}  // namespace detail
}  // namespace ELS

    #define LOG(name)do {if (ELS::detail::logger::get().IsActive()){\
    (*ELS::detail::logger::get().log())<< /*__FILE__ << " [" << __LINE__ << "] : "<< */ (name)<< std::endl;}}while(false)
    #define LOG_FN(name) ELS::detail::logger::get().put_debug_info ( __FILE__, __LINE__, #name, (name) )
    #define LOG_ON() do {ELS::detail::logger::get().On(); } while(false)
    #define LOG_OFF() do {ELS::detail::logger::get().Off(); } while(false)
#else // !CLEAN_LOG
    #define LOG(name) do{}while(false)
    #define LOG_FN(name) do{}while(false)
    #define LOG_ON() do{}while(false)
    #define LOG_OFF() do{}while(false)
#endif// !CLEAN_LOG



#if defined(CONSTRUCTOR_LOG) && ! defined(CLEAN_LOG)
    #define LOG_CONSTRUCTOR(which) do {if (ELS::detail::logger::get().IsActive()){\
        (*ELS::detail::logger::get().log())<< "**** Call to the CONSTRUCTOR "<<#which<<", at line "  <<__LINE__<< ", file " << __FILE__<< std::endl; \
        }}while(false)
    #define LOG_DESTRUCTOR(which) do {if (ELS::detail::logger::get().IsActive()){\
    (*ELS::detail::logger::get().log())<< "**** Call to the DESTRUCTOR "<<#which<<", at line "  <<__LINE__<< ", file " << __FILE__<< std::endl; \
        }}while(false)
#else
    #define LOG_CONSTRUCTOR(which) do{}while(false)
    #define LOG_DESTRUCTOR(which) do{}while(false)
#endif

#if defined(ERROR_LOG) && ! defined(CLEAN_LOG)
    #define LOG_E(message, variable) ELS::detail::logger::get().put_debug_info ("ERROR", __FILE__, __LINE__,(message), #variable , (variable) )
#else
    #define LOG_E(message, variable)do{}while(false)
#endif

#if defined(WARNING_LOG) && ! defined(CLEAN_LOG)
    #define LOG_W(message, variable) ELS::detail::logger::get().put_debug_info ("WARNING", __FILE__, __LINE__,(message), #variable , (variable) )
#else
    #define LOG_W(message, variable)do{}while(false)
#endif

#if defined(DEBUG_LOG) && ! defined(CLEAN_LOG)
    #define LOG_D(message, variable) ELS::detail::logger::get().put_debug_info ("DEBUG", __FILE__, __LINE__,(message), #variable , (variable) )
#else
    #define LOG_D(message, variable)do{}while(false)
#endif

#if defined(INFO_LOG) && ! defined(CLEAN_LOG)
    #define LOG_I(message, variable) ELS::detail::logger::get().put_debug_info ("INFO", __FILE__, __LINE__,(message), #variable , (variable) )
#else
    #define LOG_I(message, variable)do{}while(false)
#endif

#endif //TRIVIALLOGGER_H_

