cmake_minimum_required(VERSION 3.0.0)
SET(project_name TextAdventure)
SET(CMAKE_INSTALL_PREFIX < install_path >)
PROJECT (${project_name})

include(CTest)
enable_testing()

SET(app_src_h 
    src/DamageRange.h 
    src/Map.h 
    src/Monster.h 
    src/Player.h 
    src/Random.h 
    src/Weapon.h
    src/Scamander.h
    src/Tunnel.h
    src/Treasure.h
    src/TreasureBox.h
)

SET(app_src_cpp
    src/TextAdventure.cpp
    #src/DamageRange.cpp 
    src/Map.cpp 
    src/Monster.cpp 
    src/Player.cpp
    src/Random.cpp 
    src/Weapon.cpp
    src/Scamander.cpp
    src/Tunnel.cpp
    src/Treasure.cpp
    src/TreasureBox.cpp

)

ADD_EXECUTABLE(${project_name} ${app_src_h} ${app_src_cpp} )
TARGET_LINK_LIBRARIES( ${project_name} ${ADDITIONAL_LIBS})

FOREACH(onelib ${ADDITIONAL_LIBS_RELEASE})
 TARGET_LINK_LIBRARIES( ${project_name} optimized ${onelib} )
ENDFOREACH()
FOREACH(onelib ${ADDITIONAL_LIBS_DEBUG})
 TARGET_LINK_LIBRARIES( ${project_name} debug ${onelib} )
ENDFOREACH()

 INSTALL(TARGETS ${project_name} DESTINATION .)

