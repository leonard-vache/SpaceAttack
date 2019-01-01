cmake_minimum_required(VERSION 2.8.3)
project(SpaceAttack)

set(CMAKE_REQUIRED_FLAGS -g)

# Redirige la sortie de l'éxécutable dans le dossier bin
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

# Inclusion de la SDL2 a la main
#set(SDL2_INCLUDE_DIR /usr/include/SDL2
#set(SDL2_LIBRARY /usr/lib/libSDL2.so)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -ggdb")


message("source du projet par defaut : ${SpaceAttack_SOURCE_DIR}")
#message("binaire du projet par defaut: ${SpaceAttack_SOURCE_DIR}")

# Ajout du chemin où se trouve le fichier de config FindSDL2.cmake / Necessaire au "find_package"
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)


#Inclusion de la sdl + du répertoire des header et de images
include_directories(${SDL2_INCLUDE_DIR} include images)

# Charge tous les fichiers du dossier (et de ses sous dossier grace à GLOB_RECURSE) dans la variable src_file
file(
		GLOB_RECURSE
		src_file
		src/*
)

add_executable( ${PROJECT_NAME} ${src_file} )

#Configuration lors de l'édition des liens
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} -lSDL2_image -lm)
