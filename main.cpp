#include <iostream>
#include "Vertex.h"
#include "Graph.h"
#include "AdjacencyTable.h"
#include <list>

typedef std::pair<int, int> E;
typedef std::map<int, std::list<int> > G;

int main() {
//    AdjacencyTable at;
//    at+E(1,2);
//    at+E(2,3);
//    at+E(1,3);
//    at.relabel(3,9);
//    at-E(1,3);
//    !at;
//    std::cout << "here " << at.contains(E(1,3)) << std::endl;
//
//    std::cout << at << "\n\n";

//    Graph g;
//    g+3;
//    g+2;
//    g-2;
//    g+E(2,3);
//    g+E(2,3);
//    g+E(1,3);
//    g+E(1,5);
//    g-E(2,3);
//    g+E(2,3);
//    g.relabelVertex(2,9);
//
////    g.clearEdges();
//
//    std::cout << g << std::endl;
//    !g;
//    g.complete();
//
//
//    std::cout << g << std::endl;
   // std::cout << g.e();

    Graph K('K', 6);
    K.relabelAll(7, 12);
    std::cout << K << std::endl;
    std::cout << K.e() << std::endl;

    Graph C('C', 5);
    C+E(2,5);
    C|E(2,3);
    std::cout << C << std::endl;
    std::cout << C.e();
//    std::cout << C.listVertices() << std::endl;


    return 0;
}