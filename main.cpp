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
    VertexTable vt;
    vt+3;
    vt+6;
    vt-3;
    vt-2;
    cout << vt.contains(6) << vt.contains(2);
    cout << vt.size();
    cout << vt.clear().size();




    return 0;
}