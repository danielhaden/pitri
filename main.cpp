#include <iostream>
#include "Graph.h"
#include "AdjacencyList.h"

int main() {
    AdjacencyList al;
    Vertex v;
    v.color = 2;
    Vertex m;
    m = v;

    al+2;
    al[2];
    al-3;
    al-2;
    std::cout << m.color;

    return 0;
}