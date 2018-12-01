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

    typedef std::pair<int, int> E;   // undirected edge typedef
    typedef std::tuple<int, int> dE; // directed edge typedef

    // constructors
    AdjacencyList();

    // members
    Table adjacency_table;
    int size;
    int edges;
    Vertex nullvtx;


    // vertex mutators
    AdjacencyList& operator+(const int id);
    AdjacencyList& operator-(const int id);

    // undirected edge mutators
    AdjacencyList& operator+(const E edge);
    AdjacencyList& operator-(const E edge);


    // accessors
    friend std::ostream& operator<<(std::ostream& stream, const AdjacencyList& al);
    AdjacencyList& contains(const E edge);


private:
    // removes a single adjacency(i.e. edge) in table
    bool _delete(Vertex* v1, Vertex* v2);
};


#endif //PITRI_ADJACENCYLIST_H
