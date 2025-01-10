cmake_minimum_required(VERSION 2.84 FATAL_ERROR)

project(CasaDispositivi)

include_directories(include, src)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 11)

add_library(Casa
	include/Casa.h
	src/Casa.cpp
)

add_library(CicloPrefissato
	include/CicloPrefissato.h
	src/CicloPrefissato.cpp
)

add_library(Dispositivo
	include/Dispositivo.h
	src/Dispositivo.cpp
)

add_library(Manuale
	include/Manuale.h
	src/Manuale.cpp
)

add_executable(main
	main.cpp
)

target_link_libraries(main
	Casa
	CicloPrefissato
	Dispositivo
	Manuale
)
