#include <iostream>
#include "Vertex.h"
#include "Graph.h"
#include "AdjacencyTable.h"
#include <list>

typedef std::pair<int, int> E;
typedef std::map<int, std::list<int> > G;

using std::cout;
using std::endl;

int main() {

    Graph K('K', 6);
    //K.relabelAll(7, 12);
    std::cout << K << std::endl;
    std::cout << K.e() << std::endl;

    Graph C('C', 5);
    C+E(2,5);
    C|E(2,3);
    std::cout << C << std::endl;
    std::cout << C.e() <<std::endl;
//    std::cout << C.listVertices() << std::endl;

    Graph A;
    A = C;
    cout << A << endl;

    A.relabelVertex(1,7);
    A.relabelVertex(2,7);
    cout << A << endl;

    cout << A.get_vtable().size();

    return 0;
}