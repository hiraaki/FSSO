cmake_minimum_required(VERSION 3.12)
project(FSSO)

set(CMAKE_CXX_STANDARD 14)

add_executable(FSSO src/views/main.cpp src/models/Dirnode.cpp src/models/Dirnode.h src/models/Datanode.cpp src/models/Datanode.h src/models/Tabent.cpp src/models/Tabent.h src/models/Fileent.cpp src/models/Fileent.h)