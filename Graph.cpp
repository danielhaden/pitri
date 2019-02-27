//
// Created by hadend on 12/1/18.
//

#include <iostream>
#include "Graph.h"
#include "LoopException.h"
#include "ConstructorException.h"
#include "IDCollisionException.h"
#include "OutOfRangeException.h"
#include <memory>
#include <algorithm>


Graph &Graph::operator+(int v) {

    atable+v;
    vtable+v;

    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Graph &g) {
    std::cout << g.atable;
    return stream;
}

Graph &Graph::operator+(Graph::E edge) {

    etable+edge;
    atable+edge;
    vtable+edge.first;
    vtable+edge.second;

    return *this;
}

Graph &Graph::operator-(int v) {

    atable-v;
    vtable-v;

    return *this;
}

Graph &Graph::operator-(Graph::E edge) {

    atable-edge;
    etable-edge;

    return *this;
}

int Graph::v() const {
    return vtable.size();
}

int Graph::e() {
    return etable.size();
}

Graph &Graph::operator!() {

    // take complement of table
    !atable;

    etable.clear();

    for (auto const& edge : atable.getEdges()) {
        etable+(edge);
    }

    return *this;
}

Graph &Graph::clearEdges() {

    atable.clearEdges();
    etable.clear();

    return *this;
}


Graph &Graph::complete() {

    atable.complete();

    for (auto const& edge : atable.getEdges()) {
        etable+(edge);
    }

    return *this;
}

Graph::Graph(const char c, int order) {

    if (c == 'K') {         // 'K' flag produces a complete graph of order given

        // generate vertices
        for (int i = 1; i <= order; i++) {
            operator+(i);
        }
        complete();

    } else if (c == 'C') {  // 'C' flag produces a cycle graph of order given

        // generate vertices and edges
        for (int i = 1; i < order; i++) {
            operator+(E(i, i+1));
        }
        // generate final edge
        operator+(E(1, order));

    } else {
        throw ConstructorException();
    }
}

Graph &Graph::relabelVertex(int from, int to) {

    atable.relabel(from, to);
    vtable.relabel(from, to);
    etable.relabelVertex(from, to);

    return *this;
}

Graph &Graph::relabelAll(int start, int finish) {
    NList vertices = getVertexIDSet();

    // check that range is valid for graph
    if (vertices.size() != (finish - start + 1)) {
        throw IDCollisionException();
    }

    // generate set of new vertex ids
    NList new_labels;
    for (int i = start; i <= finish; i++) {
        new_labels.insert(i);
    }

    // find original ids to change
    std::set<int> diffFrom;
    std::set_difference(vertices.begin(), vertices.end(),
            new_labels.begin(), new_labels.end(),
            std::inserter(diffFrom, diffFrom.end()));

    // find new labels for ids to change
    std::set<int> diffTo;
    std::set_difference(new_labels.begin(), new_labels.end(),
                        vertices.begin(), vertices.end(),
                        std::inserter(diffTo, diffTo.end()));

    for (auto const& to : diffTo) {
        int from = *(diffFrom.begin());
        relabelVertex(from, to);
        diffFrom.erase(diffFrom.begin());
    }

    return *this;
}

std::set<int> Graph::getVertexIDSet() {
    NList vertices;

    for (auto const& v : atable.table) {
        vertices.insert(v.first);
    }
    return vertices;
}

Graph &Graph::operator|(Graph::E edge) {

    // check that edge is in graph
    if (!etable.contains(edge)) {
        return *this;
    }

    // get adjacencies of v2
    NList neighbors = atable.table[edge.first];

    // add edges from v1 to v2's neighbors
    for (auto const& n : neighbors) {
        *this+(n, edge.first);
    }

    // delete v2
    *this-edge.second;

    return *this;
}

Graph &Graph::operator=(Graph const &g) {

    // self-assignment guard
    if (this == &g) {
        return *this;
    }

    // create new vertex and edge objects for new graph copy
    for (auto const& v : g.atable.table) {
        for (auto const& u : v.second) {
            (*this)+E(u, v.first);
        }
    }

    // copy
    atable = g.atable;
    vtable = g.vtable;
    etable = g.etable;

    return *this;
}

Graph& Graph::operator+(Graph const &g) const {
    Graph lhs = *this;
    Graph rhs = g;

    lhs.relabelAll(1, lhs.v());
    rhs.relabelAll(lhs.v()+1, lhs.v()+rhs.v()+1);

    // need to overload etable, vtable, atable operator+ for self-type addition

    return rhs;
}

Graph::Graph(char c, int m, int n) {


    if (c == 'K') {         // 'K' flag produces a complete graph of order given

        // generate vertices
        for (int i = 1; i <= m+n; i++) {
            operator+(i);
        }

        // generate edges
        for (int i = 1; i <= m; i++) {
            for (int j = m+1; j <= m+n; j++) {
                operator+(E(i,j));
            }
        }

    } else {
        throw ConstructorException();
    }
}

bool Graph::isEmbedded() {
    return embedded;
}







