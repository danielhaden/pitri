//
// Created by hadend on 11/22/18.
//

#include <iostream>
#include "Graph.h"

Graph::Graph() {
    order = 0;
}

int Graph::v() {
    return order;
}

Vertex &Graph::add_vertex() {
    Vertex *v = new Vertex;
    order++;
    return *v;
}









