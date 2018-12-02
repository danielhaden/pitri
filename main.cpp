#include <iostream>
#include "Vertex.h"
#include "AdjacencyList.h"
#include "Graph.h"
#include <list>

typedef std::pair<int, int> E;
typedef std::map<int, std::list<int> > G;

int main() {
//    AdjacencyList al;
//    al+1;
//    al+2;
//    al+3;
//   // std::cout << "edges: " << al.edges << std::endl;
//    al+E(2,3);
//   // std::cout << "edges: " << al.edges << std::endl;
//    al+E(2,4);
//    al+5;
//    //std::cout << "order " << al.size;
//    al+7;
//    std::cout << al.contains(E(5,7));
//    al+E(5,7);
//    al-E(5,7);
//    std::cout << al.contains(E(5,7));
//    al+E(4,5);
//    al+E(4,5);
//    al-E(4,5);
//    al-E(4,5);
//    al+E(1,1);
    Graph Gr(G({{1, { 2,3,4}}}));
    std::cout << "G has: " << Gr.size() << std::endl;
    std::cout << Gr << std::endl;
//
//    AdjacencyList al;
//    al+E(1,2);
//    al+E(1,3);
//    al+E(1,4);
//    al.contains(E(1,4));
//    std::cout << al.contains(E(1,4));
//    std::cout << al.size;
//    std::cout << al;









    return 0;
}