# The name of our project is "EINHERI". CMakeLists files in this project can
# refer to the root source directory of the project as ${EINHERI_SOURCE_DIR} and
# to the root binary directory of the project as ${EINHERI_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
project (EINHERI)

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (src)

