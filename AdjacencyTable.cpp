//
// Created by hadend on 12/2/18.
//

#include <iostream>
#include "AdjacencyTable.h"
#include "LoopException.h"

AdjacencyTable &AdjacencyTable::operator+(int v) {
    atable.insert( std::pair<int, NList >( v, NList() ) );

    return *this;
}

AdjacencyTable &AdjacencyTable::operator+(E edge) {

    // add vertices if not present
    atable.insert( std::pair< int, NList >( edge.first,  NList() ));
    atable.insert( std::pair< int, NList >( edge.second, NList() ));

    if ( edge.first == edge.second ) {
        throw LoopException();
    }

    // add each as adjacent to eachother
    atable[edge.first].insert( edge.second );
    atable[edge.second].insert( edge.first );
}

AdjacencyTable &AdjacencyTable::operator-(int v) {
    NList neighbors = atable[v];

    // erase adjacency for all neighbors
    if ( neighbors.size() != 0 ) {
        for ( auto const& u : neighbors) {
            atable[u].erase(v);
        }
    }
    atable.erase(v);

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
