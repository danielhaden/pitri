//
// Created by hadend on 11/22/18.
//

#include <iostream>
#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {
    size = 0;
    Vertex nullvertex;
    nullvertex.id = -1;
    nullvertex.tag = "nullvertex";
    nullvertex.color = -1;
}

Vertex &AdjacencyList::operator[](const int v) {
    try {
        Vertex* v_ptr = table.at(v).first;
        return *v_ptr;

    } catch (const std::out_of_range oor) {
        std::cout << "vertex " << v << " not in table!\n";
        return nullvertex;
    }
}

Vertex &AdjacencyList::operator+(int v) {
    // try-block guards against duplicate vertex
    try {
        Vertex* v_ptr = table.at(v).first;
        std::cout << "vertex " << v << " already in table!\n";
        return *v_ptr;

    // catch-block creates new vertex
    } catch (const std::out_of_range oor) {
        Vertex* v_ptr = new Vertex(v);
        table.insert( Row( v, Entry( v_ptr, NeighborList())));
        size++;
        return *v_ptr;
    }
}

AdjacencyList &AdjacencyList::operator-(int v) {
    // try-block performs removal
    try {
        Vertex* v_ptr = table.at(v).first;
        NeighborList neighbors = table.at(v).second;

        for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
            std::cout << "here: " << *it << std::endl;
        }

        table.erase(v);
        size--;
        delete v_ptr;

    } catch (const std::out_of_range oor) {
        std::cout << "vertex " << v << " not in table!\n" << std::endl;
    }
    return *this;
}











