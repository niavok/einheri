add_executable (einheri 
main.cpp
Application.cpp
ClientWorldModel.cpp
ClientWorldEngine.cpp
GameEngine.cpp
GameEvent.cpp
GraphicEngine.cpp
Hero.cpp
InputEngine.cpp
Map.cpp
Monster.cpp
NetworkEngine.cpp
PacketDispatcher.cpp
Player.cpp
${EINHERI_SOURCE_DIR}/src/common/EinheriProtocol.cpp
${EINHERI_SOURCE_DIR}/src/common/Semaphore.cpp
)



include_directories(${EINHERI_SOURCE_DIR}/lib/sfml/include ${EINHERI_SOURCE_DIR}/src/common)


target_link_libraries (einheri sfml-system sfml-network sfml-window sfml-graphics sfml-audio GLU )


