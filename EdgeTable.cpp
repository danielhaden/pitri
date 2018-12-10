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

EdgeTable &EdgeTable::relabel(std::shared_ptr<Edge> e_ptr, EdgeTable::E edge) {
    E from = E(e_ptr->v1, e_ptr->v2);

    e_ptr->v1 = std::min(edge.first, edge.second);
    e_ptr->v2 = std::max(edge.first, edge.second);

    table.insert(std::pair<E, std::shared_ptr<Edge> >(edge, e_ptr));
    table.erase(from);

    return *this;
}
