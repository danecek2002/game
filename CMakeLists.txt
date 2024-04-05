cmake_minimum_required(VERSION 3.24)
project(zools2023_xefanova)

set(CMAKE_CXX_STANDARD 17)

add_executable(zools2023_xefanova main.cpp Weapon.h Weapon.cpp Game.cpp GameStorage.cpp Item.cpp Map.cpp Player.cpp MapDirector.h MapDirector.cpp MapBuilder.cpp DungeonMapBuilder.cpp Enemy.cpp Monster.cpp Guard.cpp)
