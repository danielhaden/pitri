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
