#include <iostream>
#include "Vertex.h"
#include "Graph.h"
#include "AdjacencyTable.h"
#include <list>

typedef std::pair<int, int> E;
typedef std::map<int, std::list<int> > G;

int main() {
//    AdjacencyTable at;
//    at+3;
//    at+E(3,2);
//    at+E(2,3);
//    at+E(1,3);
//    at-E(1,3);
//    at.complete();
//    at-E(1,3);
//    !at;
//    std::cout << "here " << at.contains(E(1,3)) << std::endl;
//
//    std::cout << at;

    Graph g;
    g+3;
    g+2;
    g-2;
    g+E(2,3);
    g+E(2,3);
    g+E(1,3);
    g+E(1,5);
    g-E(2,3);
    g+E(2,3);

//    g.clearEdges();

    std::cout << g << std::endl;
    !g;
    g.complete();


    std::cout << g << std::endl;
    std::cout << g.e();

    return 0;
}