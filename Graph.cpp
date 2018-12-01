//
// Created by hadend on 12/1/18.
//

#include "Graph.h"


Graph::Graph() {
    order = 0;
    multiedges = false;
    loops = false;
    simple = true;
}

Graph::Graph(bool simple) : simple(simple) {

}
