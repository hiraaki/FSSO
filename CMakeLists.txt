cmake_minimum_required(VERSION 3.10)
project(FSSO)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/models)

include_directories(src/models)
include_directories(src/views)

add_executable(FSSO
        src/models/Datanode.cpp
        src/models/Datanode.h
        src/models/Dirnode.cpp
        src/models/Dirnode.h
        src/models/SAD16.cpp
        src/models/SAD16.h
        src/models/Tabent.cpp
        src/models/Tabent.h
        src/views/main.cpp src/models/BootSad.cpp src/models/BootSad.h)
