# Add executable called "einheri" that is built from the source file
# "main.cpp" . The extensions are automatically found.
IF(WIN32)
    include_directories ("${EINHERI_SOURCE_DIR}/build/lib/irrlicht/include")
    LINK_DIRECTORIES( ${LINK_DIRECTORIES} ${EINHERI_SOURCE_DIR}/build/lib/irrlicht/lib)

    SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/dll)

ENDIF(WIN32)

add_executable (einheri main.cpp )


target_link_libraries (einheri Irrlicht)

