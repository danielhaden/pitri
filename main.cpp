#include <iostream>
#include "Vertex.h"
#include "Graph.h"
#include "AdjacencyTable.h"
#include "EdgeTable.h"
#include "VertexTable.h"
#include <list>

#include <QApplication>
#include <QPushButton>

typedef std::pair<int, int> E;
typedef std::map<int, std::list<int> > G;

using std::cout;
using std::endl;

int main(int argc, char **argv) {
    QApplication app (argc, argv);

    QPushButton button;
    button.setText("My text");
    button.setToolTip("A tooltip");
    button.show();

//    Graph g;
//    cout << g.e() << endl;
//    g+E(2,4);
//    cout << g.e() << endl;
//    g+E(2,3);
//    cout << g.e() << endl;
//    g+E(3,4);
//    cout << g.e() << endl;
//    g+E(4,5);
//    cout << g.e() << endl;
//    g+E(4,5);
//    cout << g.e() << endl;
//    g-E(4,5);
//    cout << g.e() << endl;
//    g-E(1,8);
//    cout << g.e() << endl;
//
//    Graph k('K', 10);
//
//
//    cout << k << endl;

    // implement string constructor
    // overload + and *
    // implement isPlanar()







    return app.exec();
}