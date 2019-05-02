cmake_minimum_required(VERSION 3.13)
project(CSCI251Assign2)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSCI251Assign2 main.cpp Crew.cpp Crew.h Officer.cpp Officer.h SkillSet.h Sector.h Ship.cpp Ship.h Hull.h Hardpoint.h Engine.h Hull.cpp)