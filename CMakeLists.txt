cmake_minimum_required(VERSION 3.12)
project(pitri)

set(CMAKE_CXX_STANDARD 14)

add_executable(pitri main.cpp Vertex.cpp Vertex.h Graph.cpp Graph.h LoopException.h AdjacencyTable.cpp AdjacencyTable.h Edge.cpp Edge.h)