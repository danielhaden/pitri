cmake_minimum_required(VERSION 3.12)
project(pitri)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)


add_executable(pitri main.cpp Vertex.cpp Vertex.h Graph.cpp Graph.h LoopException.h AdjacencyTable.cpp AdjacencyTable.h Edge.cpp Edge.h ConstructorException.h IDCollisionException.h OutOfRangeException.h EdgeTable.cpp EdgeTable.h VertexTable.cpp VertexTable.h)

target_link_libraries(pitri Qt5::Widgets)