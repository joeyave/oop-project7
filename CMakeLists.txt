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
        src/particles/Particle.cpp
        src/particles/Particle.h
        src/Utils.h src/particles/RectangleParticle.cpp src/particles/RectangleParticle.h src/particles/CircleParticle.cpp src/particles/CircleParticle.h)

target_link_libraries(project7 sfml-system sfml-window sfml-graphics sfml-network sfml-audio)