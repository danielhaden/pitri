//
// Created by hadend on 12/2/18.
//

#ifndef PITRI_ADJACENCYTABLE_H
#define PITRI_ADJACENCYTABLE_H

#include <set>
#include <map>
#include "Vertex.h"




struct AdjacencyTable {
    typedef std::set<int> NList;
    typedef std::pair<int, int> E;

    // members
    std::map<int, NList> atable;

    // vertex operators
    AdjacencyTable& operator+(int v);
    AdjacencyTable& operator-(int v);


    // edge operators
    AdjacencyTable& operator+(E edge);
    AdjacencyTable& operator-(E edge);
    AdjacencyTable& complete();

    friend std::ostream& operator<<(std::ostream& stream, const AdjacencyTable& at);

};


#endif //PITRI_ADJACENCYTABLE_H
