//
// Created by hadend on 12/1/18.
//

#ifndef PITRI_GRAPH_H
#define PITRI_GRAPH_H

#include "AdjacencyTable.h"
#include <list>

class Graph {
public:


    friend std::ostream& operator<<(std::ostream& stream, const Graph& g);

private:
    AdjacencyTable atable;
    std::map<int, Vertex*>



};


#endif //PITRI_GRAPH_H
