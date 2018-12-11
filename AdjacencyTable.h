//
// Created by hadend on 12/2/18.
//

#ifndef PITRI_ADJACENCYTABLE_H
#define PITRI_ADJACENCYTABLE_H

#include <set>
#include <map>
#include "Vertex.h"

//###############################################//
// AdjacencyTable holds the list of vertices and //
// and adjacencies as a simple adjacency list.   //
// Underlying set operations are implemented here//
// instead of in Graph.cpp                       //
//###############################################//

class AdjacencyTable {
public:
    typedef std::set<int> NList;
    typedef std::pair<int, int> E;


    // vertex operators
    AdjacencyTable& operator+(int v);           // adds a vertex (idempotent)
    AdjacencyTable& operator-(int v);           // deletes a vertex
    AdjacencyTable& relabel(int from, int to);  // changes the unique vertex id

    // edge operators
    AdjacencyTable& operator+(E edge); // adds an edge (idempotent)
    AdjacencyTable& operator-(E edge); // removes an edge
    AdjacencyTable& complete();        // introduces every edge to the graph
    AdjacencyTable& operator!();       // constructs the complement
    AdjacencyTable& clearEdges();      // removes all adjacencies, keeps vertices

    AdjacencyTable& operator=(const AdjacencyTable& at); // overloaded assignment operator

    // accessors
    friend std::ostream& operator<<(std::ostream& stream, const AdjacencyTable& at);
    bool contains(int v);
    bool contains(E edge);

    // members
    std::map<int, NList> table;

};



#endif //PITRI_ADJACENCYTABLE_H
