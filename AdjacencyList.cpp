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
        Vertex* v_ptr = new Vertex(id);
        adjacency_table.insert( std::pair<int, Entry>(id,  Entry(v_ptr, VList())) );
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

// delete v2 as adjacent to v1
bool AdjacencyList::_delete(Vertex *v1, Vertex *v2) {

    std::vector<Vertex*>::iterator it;
    for (it = adjacency_table[v1->id].second.begin(); it != adjacency_table[v1->id].second.end(); ++it) {
        if ((*it)->id == v2->id) {
            adjacency_table[v1->id].second.erase(it);
            return true;
        }
    }
    return false;
}

AdjacencyList::AdjacencyList() {
    size = 0;
    edges = 0;

    // null vertex has id -1
    Vertex nullvtx(-1);
}

AdjacencyList &AdjacencyList::operator+(const E edge) {
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


    edges++;
    return *this;
}

AdjacencyList &AdjacencyList::operator-(const E edge) {
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
    bool r1 = _delete(v1_ptr, v2_ptr);
    bool r2 = _delete(v2_ptr, v1_ptr);

    if (r1 & r2) {
        edges--;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const AdjacencyList &al) {

    for ( auto const& v : al.adjacency_table ) {

        AdjacencyList::VList neighbors = v.second.second;
        std::cout << v.first << ": ";

        if (neighbors.size() == 0) {
            std::cout << "{}\n";

        } else {
            std::cout << "{";

            std::vector<Vertex*>::iterator it;

            for (it = neighbors.begin(); it != std::prev(neighbors.end()); ++it) {

                std::cout << (*it)->id << ", ";
            }
            std::cout << neighbors.back()->id <<  "}\n";
        }
    }
    return stream;
}

