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
    Graph g('K', 6);
    cout << g;

    g.relabelVertex(4,9);





    return 0;
}