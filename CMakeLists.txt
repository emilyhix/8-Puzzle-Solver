CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(Project1)

ADD_EXECUTABLE(run 
    src/main.cpp
    src/node.cpp
    src/printMenu.cpp
    src/AStarED.cpp
    src/AStarMT.cpp
    src/UniformCost.cpp
)