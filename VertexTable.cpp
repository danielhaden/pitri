//
// Created by hadend on 12/9/18.
//

#include "VertexTable.h"
#include "OutOfRangeException.h"

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

VertexTable &VertexTable::relabel(int from, int to) {

    if (!contains(from)) {
        throw OutOfRangeException();
    }

    table.insert(std::pair<int, std::shared_ptr<Vertex> >(to, table[from]));
    table[to]->id = to;
    table.erase(from);

    return *this;
}

VertexTable &VertexTable::operator=(const VertexTable &rhs) {

    // self-assignment guard
    if (this == &rhs ) {
        return *this;
    }

    table = rhs.table;

    return *this;
}

std::map<int, std::shared_ptr<Vertex> > &VertexTable::getTable() {
    return table;
}
