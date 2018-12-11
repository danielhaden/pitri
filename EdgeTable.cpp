//
// Created by hadend on 12/9/18.
//

#include "EdgeTable.h"
#include "OutOfRangeException.h"
#include "IDCollisionException.h"

bool EdgeTable::contains(EdgeTable::E edge) {

    if (table.find(edge) == table.end()) {
        return false;

    } else {
        return true;
    }
}

EdgeTable &EdgeTable::operator+(EdgeTable::E edge) {
    int v1 = std::min(edge.first, edge.second);
    int v2 = std::max(edge.first, edge.second);

    // check that edge is not in table already
    if (table.find(E(v1, v2)) != table.end()) {
        return *this;
    }

    // add edge
    table[edge] = std::shared_ptr<Edge>(new Edge(v1, v2));

    return *this;
}

EdgeTable &EdgeTable::operator-(EdgeTable::E edge) {
    int v1 = std::min(edge.first, edge.second);
    int v2 = std::max(edge.first, edge.second);

    // check that edge is in table already
    if (table.find(E(v1, v2)) == table.end()) {
        return *this;
    }

    // remove edge
    table.erase(E(v1, v2));

    return *this;
}

int EdgeTable::size() {
    return table.size();
}

EdgeTable &EdgeTable::clear() {
    table.clear();
    return *this;
}

Edge &EdgeTable::operator[](EdgeTable::E edge) {
    return *(table[edge]);
}



EdgeTable::pointer_set EdgeTable::operator[](int vertex) {
    pointer_set edges;

    for (auto const& edge : table ) {
        if ((vertex == edge.first.first) | (vertex == edge.first.second)) {
            edges.insert(edge.second);
        }
    }
    return edges;
}

EdgeTable &EdgeTable::operator=(const EdgeTable &rhs) {

    // self-assignment guard
    if ( this == &rhs ) {
        return *this;
    }

    table = rhs.table;

    return *this;
}

std::map<std::pair<int, int>, std::shared_ptr<Edge> > &EdgeTable::getTable() {
    return table;
}

EdgeTable &EdgeTable::relabelVertex(int from, int to) {
    NList vertices = getVertices();
    if ((vertices.find(from) == vertices.end()) | (vertices.find(to) != vertices.end())) {
        return *this;
    }

    for( auto const& entry : table ) {
        if( entry.first.first == from ) {
            E eFrom(std::min(entry.first.first, from), std::min(entry.first.first, from));
            E eTo(std::min(entry.first.first, to), std::min(entry.first.first, to));

            table[eTo] = table[eFrom];
            table.erase(eFrom);

        } else if ( entry.first.second == from ) {
            E eFrom(std::min(entry.first.second, from), std::min(entry.first.second, from));
            E eTo(std::min(entry.first.second, to), std::min(entry.first.second, to));

            table[eTo] = table[eFrom];
            table.erase(eFrom);
        }
    }
    return *this;
}

std::set<int> EdgeTable::getVertices() {
    NList vertices;

    for( auto const& entry : table) {
        vertices.insert(entry.first.first);
    }

    return vertices;
}
