#include <iostream>
#include "Vertex.h"
#include "Graph.h"
#include "AdjacencyTable.h"
#include "EdgeTable.h"
#include <list>

typedef std::pair<int, int> E;
typedef std::map<int, std::list<int> > G;

using std::cout;
using std::endl;

int main() {
    EdgeTable et;
    et+E(2,3);
    cout << (et[E(2,3)]).v1;
    et-E(2,3);

    cout << et.size();



    return 0;
}