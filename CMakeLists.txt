cmake_minimum_required(VERSION 3.12)
project(pitri)

set(CMAKE_CXX_STANDARD 14)

add_executable(pitri main.cpp Graph.cpp Graph.h Vertex.cpp Vertex.h Edge.cpp Edge.h)