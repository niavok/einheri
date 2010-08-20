# Add executable called "einheri" that is built from the source file
# "main.cpp" . The extensions are automatically found.
IF(WIN32)
    include_directories ("${EINHERI_SOURCE_DIR}/build/lib/irrlicht/include")
    include_directories ("${EINHERI_SOURCE_DIR}/build/lib/SDL/include")
    LINK_DIRECTORIES( ${LINK_DIRECTORIES} ${EINHERI_SOURCE_DIR}/build/lib/irrlicht/lib)
    LINK_DIRECTORIES( ${LINK_DIRECTORIES} ${EINHERI_SOURCE_DIR}/build/lib/SDL/lib)
ENDIF(WIN32)

add_executable (einheri main.cpp )


IF(WIN32)
    target_link_libraries (einheri mingw32)

ENDIF(WIN32)
target_link_libraries (einheri SDLmain SDL Irrlicht)
