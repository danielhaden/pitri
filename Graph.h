//
// Created by hadend on 11/22/18.
//

#ifndef PITRI_GRAPH_H
#define PITRI_GRAPH_H


#include <vector>
#include <map>
#include <list>
#include "Vertex.h"

class Graph {
public:
    Graph();

    Vertex& add_vertex();
    Vertex& add_vertex(int vertex_id);

    bool add_edge(int v1, int v2);

    int v();

private:
    std::map<Vertex*, std::vector<Vertex*> > AdjacencyList;
    int order;
};


#endif //PITRI_GRAPH_H
