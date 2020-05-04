cmake_minimum_required(VERSION 3.16)
project(project7)

set(CMAKE_CXX_STANDARD 20)

link_libraries(stdc++fs) #link the filesystem

# SFML library
include_directories(dependencies/SFML-2.5.1/include)
set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/dependencies/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

add_executable(project7 main.cpp
        src/Application.cpp
        src/Application.h
        src/Constants.h
        src/TextureHolder.h
        src/factory/ParticleFactory.cpp
        src/factory/ParticleFactory.h
        src/ParticleType.cpp
        src/ParticleType.h
        src/Particle.cpp
        src/Particle.h
        src/SquareParticle.cpp
        src/SquareParticle.h
        src/CircleParticle.cpp
        src/CircleParticle.h
        src/factory/SingleParticleFactory.cpp
        src/factory/SingleParticleFactory.h src/Utils.h)

target_link_libraries(project7 sfml-system sfml-window sfml-graphics sfml-network sfml-audio)