cmake_minimum_required(VERSION 3.13)
project(CSCI251Assign2)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSCI251Assign2 main.cpp Crew.cpp Crew.h Officer.cpp Officer.h Sector.h Sector.cpp Ship.cpp Ship.h ShipBuilder.cpp ShipBuilder.h Hull.h Hardpoint.h Engine.h Sector.h CombatManager.cpp CombatManager.h Enemy.cpp Enemy.h Alien.cpp Alien.h)