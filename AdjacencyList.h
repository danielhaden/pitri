//
// Created by hadend on 11/23/18.
//

#ifndef PITRI_ADJACENCYLIST_H
#define PITRI_ADJACENCYLIST_H


#include "Vertex.h"
#include <vector>
#include <map>

struct AdjacencyList {
    // #######################################################
    // #Table:                                               #
    // #| index (id) | vertex ptr | vector of neighbor ptrs |#
    // #             |<-------------- Entry --------------->|#
    // #                          |<-------- VList -------->|#
    // #######################################################
    typedef std::vector < Vertex* > VList;
    typedef std::pair< Vertex*, VList > Entry;
    typedef std::map< int, Entry > Table;

    // constructors
    AdjacencyList();

    // members
    Table adjacency_table;
    int size;
    Vertex nullvtx;


    // vertex mutators
    AdjacencyList& operator+(const int id);
    AdjacencyList& operator-(const int id);

    // edge mutators
    AdjacencyList& operator+(const std::pair<int, int> edge);
    AdjacencyList& operator-(const std::pair<int, int> edge);




private:
    // removes a single adjacency(i.e. edge) in table
    void _delete(Vertex* v1, Vertex* v2);
};


#endif //PITRI_ADJACENCYLIST_H
