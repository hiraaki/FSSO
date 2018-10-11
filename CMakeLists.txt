cmake_minimum_required(VERSION 3.10)
project(Trabson_3)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/models)

add_executable(Trabson_3
        src/models/BootSAD.cpp
        src/models/BootSAD.h
        src/models/Datanode.cpp
        src/models/Datanode.h
        src/models/Dirnode.cpp
        src/models/Dirnode.h
        src/models/SAD16.cpp
        src/models/SAD16.h
        src/models/Tabent.cpp
        src/models/Tabent.h
        src/views/main.cpp)
