### Configure library
SET(LIBNAME einheri-client)

REQUIRE_LIB(SFML)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIRS})

### Configure the src
FILE(GLOB_RECURSE ${LIBNAME}_SRC "./*.cpp" "./*.h")

### Create the lib
ADD_LIBRARY(${LIBNAME} ${${LIBNAME}_SRC}) 

### Install and Uninstall 
INSTALL(TARGETS ${${LIBNAME}_LIB}
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
		COMPONENT lib${LIBNAME} )
