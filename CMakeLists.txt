cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(Ping_Pong)

# Utilisation de C++ 11 minimum
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Définition des dossiers sources et include
set(SRC_DIR src)
set(INCLUDE_DIR include)
set(BIN_DIR app)

# Ajout des fichiers sources
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

# Ajout de l'exécutable dans le dossier app
add_executable(${PROJECT_NAME} ${SOURCES})

# Spécification du dossier include
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

# Liaison avec les bibliothèques SFML
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)

# Définition du dossier de sortie de l'exécutable
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BIN_DIR})
