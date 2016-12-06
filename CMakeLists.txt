cmake_minimum_required(VERSION 2.8.9)
project(Proyecto)

include_directories(include) 

set(SOURCES src/main.cpp src/Dijkstra.cpp src/Nodo.cpp src/Dijkstra.cpp)

add_executable(Proyecto ${SOURCES})
