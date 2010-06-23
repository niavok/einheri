# Add executable called "einheri" that is built from the source file
# "main.cpp" . The extensions are automatically found.

include_directories (${EINHERI_SOURCE_DIR}/lib/irrlicht/include)

add_executable (einheri main.cpp)



target_link_libraries (einheri Irrlicht)

