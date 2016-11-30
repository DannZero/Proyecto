
//esto va en cmake

cmake_minimum_required(VERSION 2.8.9)
project(Lista)

include_directories(include) 

set(SOURCES src/Nodo.cpp src/main.cpp)

add_executable(lista ${SOURCES})


/*
Después de guardar se va a la terminal

cd Lista
build CMakeLists.txt include src
cmake ..

make 



*/ 