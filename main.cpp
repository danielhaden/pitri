#include <iostream>
#include "Graph.h"

int main() {
    Vertex v;
    v.id = 1;
    Vertex v1;
    v1.id = 2;
    std::cout << (v > v1);
    Graph g;

    return 0;
}