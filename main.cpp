#include <iostream>
#include "Vertex.h"
#include "Edge.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Vertex v1;
    v1.set_pos(1.23,2.4495);

    std::cout << v1.x_pos;
    return 0;
}