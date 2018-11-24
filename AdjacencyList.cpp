//
// Created by hadend on 11/23/18.
//

#include <iostream>
#include "AdjacencyList.h"

AdjacencyList &AdjacencyList::operator+(const int id) {
    try {
        adjacency_table.at(id);
        std::cout << "vertex " << id << " already in AdjacencyList)!\n";

    } catch(std::out_of_range orr) {
        Vertex* v_ptr = new Vertex();
        adjacency_table[id] = Entry(v_ptr, VList());
        size++;

    }
    return *this;
}

AdjacencyList &AdjacencyList::operator-(const int id) {
    try {
        Entry entry = adjacency_table.at(id);
        VList neighbors = entry.second;

        // delete adjacencies/edges of deleted vertex
        for(std::vector<Vertex*>::iterator it = neighbors.begin(); it != neighbors.end(); ++it) {
            _delete(*it, entry.first);
        }
        size--;

    } catch(std::out_of_range oor) {
        std::cout << "vertex " << id << " not in AdjacencyList!\n";
    }
    return *this;
}

void AdjacencyList::_delete(Vertex *v1, Vertex *v2) {
    VList n = adjacency_table[v1->id].second;

    for(std::vector<Vertex*>::iterator it = n.begin(); it != n.end(); ++it) {
        if (*it == v2) {
            adjacency_table[v1->id].second.erase( it );
            break;
        }
    }
}

AdjacencyList::AdjacencyList() {
    size = 0;

    // null vertex has id -1
    Vertex nullvtx(-1);
}

AdjacencyList &AdjacencyList::operator+(const std::pair<int, int> edge) {
    Vertex* v1_ptr;
    Vertex* v2_ptr;

    // catches missing v1 in table
    try {
        v1_ptr = adjacency_table.at(edge.first).first;

    } catch (std::out_of_range oor) {

        // create missing vertex
        operator+(edge.first);
        v1_ptr = adjacency_table[edge.first].first;
    }

    // catches missing v2 in table
    try {
        v2_ptr = adjacency_table.at(edge.second).first;

    } catch (std::out_of_range oor) {

        // create missing vertex
        operator+(edge.second);
        v2_ptr = adjacency_table[edge.second].first;
    }

    // add edge to table
    adjacency_table[edge.first].second.push_back(v2_ptr);
    adjacency_table[edge.second].second.push_back(v1_ptr);

    return *this;
}

AdjacencyList &AdjacencyList::operator-(const std::pair<int, int> edge) {
    Vertex* v1_ptr;
    Vertex* v2_ptr;

    // catches missing v1 in table
    try {
        v1_ptr = adjacency_table.at(edge.first).first;

    } catch (std::out_of_range oor) {
        std::cout << "vertex " << edge.first << " not in AdjacencyList!\n";
        return *this;
    }

    // catches missing v2 in table
    try {
        v2_ptr = adjacency_table.at(edge.second).first;

    } catch (std::out_of_range oor) {
        std::cout << "vertex " << edge.first << " not in AdjacencyList!\n";
        return *this;
    }

    // delete edge
    _delete(v1_ptr, v2_ptr);

    return *this;
}
