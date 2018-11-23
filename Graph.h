//
// Created by hadend on 11/22/18.
//

#ifndef PITRI_GRAPH_H
#define PITRI_GRAPH_H


#include <vector>
#include <map>
#include "Vertex.h"

class Graph {
public:
    bool contains(Vertex v);

    bool add_vertex(Vertex v);

    bool del_vertex(Vertex v);

private:
    std::map< Vertex, std::vector<Vertex> > AdjacencyList;
    int order;
};


#endif //PITRI_GRAPH_H
