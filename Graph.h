//
// Created by hadend on 12/1/18.
//

#ifndef PITRI_GRAPH_H
#define PITRI_GRAPH_H


#include "AdjacencyList.h"

class Graph {
public:
    Graph();
    Graph(bool simple);


private:
    AdjacencyList adjacency_list;
    int order;
    bool multiedges;
    bool loops;
    bool simple;


};


#endif //PITRI_GRAPH_H
