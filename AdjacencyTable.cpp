//
// Created by hadend on 12/2/18.
//

#include <iostream>
#include <algorithm>
#include "AdjacencyTable.h"
#include "LoopException.h"
#include "IDCollisionException.h"

AdjacencyTable &AdjacencyTable::operator+(int v) {

    // add vertex if not already present
    if (table.find(v) == table.end()) {
        table.insert(std::pair<int, NList>(v, NList()));
    }

    return *this;
}

AdjacencyTable &AdjacencyTable::operator+(E edge) {

    // add vertices if not present
    operator+(edge.first);
    operator+(edge.second);

    if ( edge.first == edge.second ) {
        throw LoopException();
    }

    // add each as adjacent to eachother
    table[edge.first].insert( edge.second );
    table[edge.second].insert( edge.first );
}

AdjacencyTable &AdjacencyTable::operator-(int v) {

    if (table.find(v) != table.end()) {

        NList neighbors = table[v];

        // erase adjacency for all neighbors
        if (neighbors.size() != 0) {
            for (auto const &u : neighbors) {
                table[u].erase(v);
            }
        }
        table.erase(v);
    }

    return *this;
}

std::ostream &operator<<(std::ostream &stream, const AdjacencyTable &at) {

    for ( auto const& v : at.table ) {

        AdjacencyTable::NList neighbors = v.second;
        std::cout << v.first << ": ";

        if (neighbors.size() == 0) {
            std::cout << "{}\n";

        } else {
            std::cout << "{";

            std::set<int>::iterator it;

            for (it = neighbors.begin(); it != std::prev(neighbors.end()); ++it) {

                std::cout << *it << ", ";
            }
            it = --neighbors.end();
            std::cout << *it << "}" << std::endl;
        }
    }
    return stream;
}

AdjacencyTable &AdjacencyTable::operator-(AdjacencyTable::E edge) {

    // check that vertices are in table
    if ((table.find(edge.first) == table.end()) | (table.find(edge.second) == table.end())) {
        return *this;
    }

    table[edge.first].erase(edge.second);
    table[edge.second].erase(edge.first);
    return *this;
}

AdjacencyTable &AdjacencyTable::complete() {
    NList all;

    // get all vertices in table
    for( auto const& v : table) {
        all.insert(v.first);
    }

    // set neighbors as every vertex for each vertex
    for( auto const& v : all) {
        table[v] = all;
    }
    return *this;
}

AdjacencyTable &AdjacencyTable::operator!() {
    NList all;

    // get all vertices in table
    for( auto const& v : table) {
        all.insert(v.first);
    }

    for( auto const& u : all) {
        NList difference;
        std::set_difference(all.begin(), all.end(),
                table[u].begin(), table[u].end(),
                std::inserter(difference, difference.end()));

        difference.erase(u);
        table[u] = difference;
    }
    return *this;
}

bool AdjacencyTable::contains(int v) {
    std::map<int, NList>::iterator it;
    it = table.find(v);

    if (it != table.end()) {
        return true;
    }
    return false;
}

bool AdjacencyTable::contains(AdjacencyTable::E edge) {
    std::map<int, NList>::iterator it;
    it = table.find(edge.first);

    if (it != table.end()) {
        std::set<int>::iterator jt;
        jt = table[edge.first].find(edge.second);

        if (jt != table[edge.first].end()) {
            return true;
        }
    }
    return false;

}

AdjacencyTable &AdjacencyTable::relabel(int from, int to) {

    // check that new id is not already used
    if (table.find(to) != table.end()) {
        throw IDCollisionException();
    }

    // change key of vertex
    NList neighbors = table[from];
    table.insert(std::pair<int, NList> (to, neighbors));
    table.erase(from);

    // change adjacency name
    for (auto const& v : neighbors) {
        table[v].erase(from);
        table[v].insert(to);
    }
    return *this;
}

AdjacencyTable &AdjacencyTable::operator=(const AdjacencyTable &at) {

    // self-assignment guard
    if (this == &at) {
        return *this;
    }

    // copy
    table = at.table;

    return *this;
}

AdjacencyTable &AdjacencyTable::clearEdges() {
    for (auto & entry : table) {
        entry.second = NList();
    }
}
