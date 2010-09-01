add_executable (einheri-server 
main.cpp
Application.cpp
GameEngine.cpp
GameEvent.cpp
Hero.cpp
IdGenerator.cpp
Map.cpp
Monster.cpp
NetworkClient.cpp
NetworkEngine.cpp
NetworkNotifier.cpp
PacketDispatcher.cpp
Player.cpp
WorldEngine.cpp
WorldModel.cpp
${EINHERI_SOURCE_DIR}/src/common/EinheriProtocol.cpp
${EINHERI_SOURCE_DIR}/src/common/Semaphore.cpp
)



include_directories(${EINHERI_SOURCE_DIR}/lib/sfml/include ${EINHERI_SOURCE_DIR}/src/common)


target_link_libraries (einheri-server sfml-system sfml-network)
