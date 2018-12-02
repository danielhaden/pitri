#include <iostream>
#include "Vertex.h"
#include "AdjacencyList.h"
#include "Graph.h"
#include "AdjacencyTable.h"
#include <list>

typedef std::pair<int, int> E;
typedef std::map<int, std::list<int> > G;

int main() {
    AdjacencyTable at;
    at+3;
    at+E(3,2);
    at+E(2,3);
    at+E(1,3);
    at-E(1,3);

    std::cout << at;
    return 0;
}