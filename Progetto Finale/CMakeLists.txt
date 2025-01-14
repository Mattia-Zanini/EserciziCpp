# Autore: Zanini Mattia
cmake_minimum_required(VERSION 2.84 FATAL_ERROR)

set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_C_FLAGS_RELEASE "-O2")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 11)

set(CMAKE_BUILD_TYPE Release)

project(CasaDispositivi)

include_directories(include)

add_library(
    ${PROJECT_NAME} SHARED
    src/Casa.cpp
    src/Dispositivo.cpp
		src/CicloPrefissato.cpp
		src/Manuale.cpp
)

add_executable(main src/main.cpp)
target_link_libraries(main ${PROJECT_NAME})