//
// Created by hadend on 11/22/18.
//

#ifndef PITRI_ADJACENCYLIST_H
#define PITRI_ADJACENCYLIST_H


#include <vector>
#include <map>
#include "Vertex.h"

struct AdjacencyList {
    // Table refers to the underlying AdjacencyList data structure:
    // ###############################################################
    // | vertex id | vertex pointer| vector of pointers to neighbors |
    // |<----------------------- Row ------------------------------->|
    // |           |<----------------- Entry ----------------------->|
    // |                            |<------ Neighbor List --------->|
    // ###############################################################
    typedef std::vector<Vertex*> NeighborList;
    typedef std::pair< Vertex*, NeighborList > Entry;
    typedef std::pair< int, Entry > Row;
    typedef std::map< int, Entry > Table;

    // Constructors
    AdjacencyList();

    // Variables
    Table table;
    int size;
    Vertex nullvertex;

    // Vertex Mutators
    Vertex& operator[] (const int v);
    Vertex& operator+ (int v);
    AdjacencyList& operator- (int v);

    // Edge Mutators
    AdjacencyList& operator+ (const int v1, const int v2);
    AdjacencyList& operator- (const int v1, const int v2);


};


#endif //PITRI_ADJACENCYLIST_H
