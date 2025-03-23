cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(Ping_Pong)

# Utilisation de C++ 11 minimum
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ajout de l'executable
add_executable(Ping_Pong main.cpp)

# Liaison avec les bibliothèques SFML
target_link_libraries(Ping_Pong PRIVATE sfml-system sfml-window sfml-graphics)