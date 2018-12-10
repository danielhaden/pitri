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
    if (atable.find(v) == atable.end()) {
        atable.insert(std::pair<int, NList>(v, NList()));
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
    atable[edge.first].insert( edge.second );
    atable[edge.second].insert( edge.first );
}

AdjacencyTable &AdjacencyTable::operator-(int v) {

    if (atable.find(v) != atable.end()) {

        NList neighbors = atable[v];

        // erase adjacency for all neighbors
        if (neighbors.size() != 0) {
            for (auto const &u : neighbors) {
                atable[u].erase(v);
            }
        }
        atable.erase(v);
    }

    return *this;
}

std::ostream &operator<<(std::ostream &stream, const AdjacencyTable &at) {

    for ( auto const& v : at.atable ) {

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
    atable[edge.first].erase(edge.second);
    atable[edge.second].erase(edge.first);
    return *this;
}

AdjacencyTable &AdjacencyTable::complete() {
    NList all;

    // get all vertices in table
    for( auto const& v : atable) {
        all.insert(v.first);
    }

    // set neighbors as every vertex for each vertex
    for( auto const& v : all) {
        atable[v] = all;
    }
    return *this;
}

AdjacencyTable &AdjacencyTable::operator!() {
    NList all;

    // get all vertices in table
    for( auto const& v : atable) {
        all.insert(v.first);
    }

    for( auto const& u : all) {
        NList difference;
        std::set_difference(all.begin(), all.end(),
                atable[u].begin(), atable[u].end(),
                std::inserter(difference, difference.end()));

        difference.erase(u);
        atable[u] = difference;
    }
    return *this;
}

bool AdjacencyTable::contains(int v) {
    std::map<int, NList>::iterator it;
    it = atable.find(v);

    if (it != atable.end()) {
        return true;
    }
    return false;
}

bool AdjacencyTable::contains(AdjacencyTable::E edge) {
    std::map<int, NList>::iterator it;
    it = atable.find(edge.first);

    if (it != atable.end()) {
        std::set<int>::iterator jt;
        jt = atable[edge.first].find(edge.second);

        if (jt != atable[edge.first].end()) {
            return true;
        }
    }
    return false;

}

AdjacencyTable &AdjacencyTable::relabel(int from, int to) {

    // check that new id is not already used
    if (atable.find(to) != atable.end()) {
        throw IDCollisionException();
    }

    // change key of vertex
    NList neighbors = atable[from];
    atable.insert(std::pair<int, NList> (to, neighbors));
    atable.erase(from);

    // change adjacency name
    for (auto const& v : neighbors) {
        atable[v].erase(from);
        atable[v].insert(to);
    }
    return *this;
}

AdjacencyTable &AdjacencyTable::operator=(const AdjacencyTable &at) {

    // self-assignment guard
    if (this == &at) {
        return *this;
    }

    // copy
    atable = at.atable;

    return *this;
}

AdjacencyTable &AdjacencyTable::clearEdges() {
    for (auto & entry : atable) {
        entry.second = NList();
    }
}
