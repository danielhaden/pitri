#include <iostream>
#include "Vertex.h"
#include "Graph.h"
#include "AdjacencyTable.h"
#include "EdgeTable.h"
#include "VertexTable.h"
#include <list>

typedef std::pair<int, int> E;
typedef std::map<int, std::list<int> > G;

using std::cout;
using std::endl;

int main() {
    Graph g;
    g+E(2,4);
    g+E(2,3);
    g+E(3,4);
    g+E(4,5);
    g+E(4,5);
    g-E(4,5);
    g-E(1,8);
    g-9;
    cout << g.v() << endl;
    cout << g;

    g.relabelVertex(4,9);





    return 0;
}