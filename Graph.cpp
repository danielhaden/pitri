//
// Created by hadend on 11/22/18.
//

#include "Graph.h"

bool Graph::contains(Vertex v) {
    if (AdjacencyList.find(v) == AdjacencyList.end()) {
        return false;

    } else {
        return true;
    }
}
