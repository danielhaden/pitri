//
// Created by hadend on 11/20/18.
//

#ifndef PITRI_EDGE_H
#define PITRI_EDGE_H

#include "Vertex.h"

struct Edge {
    Vertex v1;
    Vertex v2;
    int color;
    std::string label;
};


#endif //PITRI_EDGE_H
