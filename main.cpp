#include <iostream>
#include "Vertex.h"
#include "Edge.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Vertex v1;
    Vertex ve;
    v1.color=3;
    ve.color=5;
    Edge e;
    e.v1=v1;
    e.v2=ve;
    std::cout << e.v2.color;
    return 0;
}