cmake_minimum_required(VERSION 3.16)
project(project7)

set(CMAKE_CXX_STANDARD 20)

# SFML library
include_directories(dependencies/SFML-2.5.1/include)
set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/dependencies/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

add_executable(project7 main.cpp src/Application.cpp src/Application.h src/Constants.h src/shapes/factory/ShapesFactory.h src/shapes/circle/Circle.h src/shapes/factory/PastelShapesFactory.cpp src/shapes/factory/PastelShapesFactory.h src/shapes/factory/NeonShapesFactory.cpp src/shapes/factory/NeonShapesFactory.h src/shapes/circle/PastelCircle.cpp src/shapes/circle/PastelCircle.h src/shapes/circle/NeonCircle.cpp src/shapes/circle/NeonCircle.h src/Config.cpp src/Config.h src/shapes/square/Rectangle.h src/shapes/square/PastelRectangle.cpp src/shapes/square/PastelRectangle.h src/shapes/square/NeonRectangle.cpp src/shapes/square/NeonRectangle.h)

target_link_libraries(project7 sfml-system sfml-window sfml-graphics sfml-network sfml-audio)