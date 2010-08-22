add_executable (einheri 
main.cpp
Application.cpp
GraphicEngine.cpp
InputEngine.cpp
Semaphore.cpp
Heroes.cpp
ClientWorldModel.cpp
ClientWorldEngine.cpp
)



include_directories(${EINHERI_SOURCE_DIR}/lib/sfml/include)


target_link_libraries (einheri sfml-system sfml-window sfml-graphics sfml-audio GLU )


