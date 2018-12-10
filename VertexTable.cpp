//
// Created by hadend on 12/9/18.
//

#include "VertexTable.h"

VertexTable &VertexTable::operator+(int vertex) {

    // check that vertex is not in table already
    if (table.find(vertex) != table.end()) {
        return *this;
    }

    table[vertex] = std::shared_ptr<Vertex>(new Vertex(vertex));

    return *this;
}

VertexTable &VertexTable::operator-(int vertex) {

    // check that vertex is not in table already
    if (table.find(vertex) != table.end()) {
        return *this;
    }

    table.erase(vertex);

    return *this;

}

bool VertexTable::contains(int vertex) {

    if (table.find(vertex) != table.end()) {
        return true;

    } else {
        return false;
    }
}

VertexTable &VertexTable::clear() {
    table.clear();
    return *this;
}

Vertex &VertexTable::operator[](int vertex) {
    return *(table[vertex]);

}

int VertexTable::size() {
    return table.size();
}
