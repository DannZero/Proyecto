


cmake_minimum_required(VERSION 2.8.9)
project(Proyecto)

include_directories(include) 

set(SOURCES src/Nodo.cpp src/main.cpp)

add_executable(lista ${SOURCES})
