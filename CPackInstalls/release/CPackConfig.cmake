IF(NOT CMAKE_CURRENT_SOURCE_DIR) # Standalone
	IF(WIN32 AND NOT UNIX)
		SET(CMAKE_SOURCE_DIR "XXX")
		SET(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/Projects/NMake")
		SET(CPACK_CMAKE_GENERATOR "Visual Studio 9 2008")
	ELSE(WIN32 AND NOT UNIX)
		SET(CMAKE_SOURCE_DIR "XXX")
		SET(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/Projects/$MakeFile")
		SET(CPACK_CMAKE_GENERATOR "Unix Makefiles")
	ENDIF(WIN32 AND NOT UNIX)
	SET(CMAKE_PROJECT_NAME "PyGMAlion")
ENDIF()

INCLUDE("${CMAKE_SOURCE_DIR}/CMakeModules/CreatePackage.cmake")

BEGIN_PACKAGE( "EINHERI"
				DESCRIPTION ""
				FILES_DIRECTORY "${CMAKE_SOURCE_DIR}/packaging/release"
				ENV_VARIABLE "EINHERI_ROOT")

# Add the parameters that are not seted in the macros
#SET(CPACK_PACKAGE_EXECUTABLES) 
#SET(CPACK_NSIS_DISPLAY_NAME )
#SET(CPACK_NSIS_MODIFY_PATH)

ADD_COMPONENT( applications
				DISPLAY_NAME "The applications"
				REQUIRED)
ADD_COMPONENT( files
				DISPLAY_NAME "Files"
				DESCRIPTION "Some configuration files"
				REQUIRED)
