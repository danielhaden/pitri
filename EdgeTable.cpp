//
// Created by hadend on 12/9/18.
//

#include "EdgeTable.h"

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
