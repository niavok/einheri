
MACRO(USE)
	FOREACH(arg ${ARGN})
		STRING(TOUPPER ${arg} ARG_U)
		FIND_PACKAGE(${arg})
		INCLUDE_DIRECTORIES(${ARG_U}_INCLUDE_DIRS)
	ENDFOREACH()
ENDMACRO()

MACRO(LINK EXE_NAME)
	FOREACH(arg ${ARGN})
		STRING(TOUPPER ${arg} ARG_U)
		TARGET_LINK_LIBRARIES(${EXE_NAME} ${ARG_U}_LIBRARIES)
	ENDFOREACH()
ENDMACRO()

# Usage: list_subdirectories(the_list_is_returned_here C:/cwd 1)
macro(list_subdirectories retval curdir return_relative)
	file(GLOB_RECURSE sub-dir RELATIVE ${curdir} * )
	set(list_of_dirs "")
	foreach(dir ${sub-dir})
		STRING(REGEX REPLACE "/[^/]+$" "" dir ${dir})
		if(IS_DIRECTORY ${curdir}/${dir} AND NOT dir MATCHES ".*\\.svn.*")
			if (${return_relative})
				set(list_of_dirs ${list_of_dirs} ${dir})
			else()
				set(list_of_dirs ${list_of_dirs} ${curdir}/${dir})
			endif()
		endif()
	endforeach()
	set(${retval} ${list_of_dirs})
endmacro()


### Set the folders in Visual
MACRO(GROUP_FILES_FROM THIS_DIRECTORY)
	list_subdirectories(SUB_DIRS ${THIS_DIRECTORY} 1)
	FOREACH(DIR ${SUB_DIRS})
		FILE(GLOB FILES ${DIR}/*.cpp ${DIR}/*.h)
		SOURCE_GROUP(${DIR} FILES ${FILES})
	ENDFOREACH()
ENDMACRO()

MACRO(GROUP_FILES)
	GROUP_FILES_FROM(${CMAKE_CURRENT_SOURCE_DIR})
ENDMACRO()

MACRO(REQUIRE_LIB LIB_NAME)
    IF(NOT ${LIB_NAME}_FOUND)
        MESSAGE(FATAL_ERROR "${LIB_NAME} requiered but NOT FOUND.")
    ENDIF()
ENDMACRO()

MACRO(CREATE_VERSION_H_HERE
            VERSION_NAME_PREFIX
            DEFAULT_VERSION_MAJOR DEFAULT_VERSION_MINOR DEFAULT_VERSION_PATCH
            TRY_USE_SVN)
    CREATE_VERSION_H(${CMAKE_CURRENT_SOURCE_DIR} ${VERSION_NAME_PREFIX} ${DEFAULT_VERSION_MAJOR} ${DEFAULT_VERSION_MINOR} ${DEFAULT_VERSION_PATCH} ${TRY_USE_SVN})   
ENDMACRO()

MACRO(CREATE_VERSION_H
            WHERE
            VERSION_NAME_PREFIX
            DEFAULT_VERSION_MAJOR DEFAULT_VERSION_MINOR DEFAULT_VERSION_PATCH
            TRY_USE_SVN)
    FIND_PACKAGE(Subversion)
    # wierd things appens with the variable declared as input in a macro...   
    SET(TRY_USE_SVN ${TRY_USE_SVN})# I must do this to make sure the IF is evaluated corectly.
    SET(VERSION_NAME_PREFIX ${VERSION_NAME_PREFIX})# same thing with the configure file.
    IF(TRY_USE_SVN AND Subversion_FOUND AND EXISTS "${WHERE}/.svn")
        Subversion_WC_INFO(${CMAKE_CURRENT_SOURCE_DIR} svninfo)
        SET(${VERSION_NAME_PREFIX}_REVISION ${svninfo_WC_LAST_CHANGED_REV})
        SET(${VERSION_NAME_PREFIX}_VERSION_MAJOR ${${VERSION_NAME_PREFIX}_REVISION})
        SET(${VERSION_NAME_PREFIX}_VERSION_MINOR 0)
        SET(${VERSION_NAME_PREFIX}_VERSION_PATCH 0)
    ELSE()
        SET(${VERSION_NAME_PREFIX}_REVISION ${DEFAULT_VERSION_MAJOR})
        SET(${VERSION_NAME_PREFIX}_VERSION_MAJOR ${DEFAULT_VERSION_MAJOR})
        SET(${VERSION_NAME_PREFIX}_VERSION_MINOR ${DEFAULT_VERSION_MINOR})
        SET(${VERSION_NAME_PREFIX}_VERSION_PATCH ${DEFAULT_VERSION_PATCH})
    ENDIF()
    CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/include/version.h.in ${WHERE}/version.h)
ENDMACRO()

