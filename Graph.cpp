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
    int v1 = std::min(edge.first, edge.second);
    int v2 = std::max(edge.first, edge.second);

    // check that edge is not already in graph
    if(atable.contains(edge)) {
        return *this;
    }

    // add vertices
    operator+(edge.first);
    operator+(edge.second);

    // lower vertex is always first
    if (edge.first > edge.second) {
        int tmp = edge.second;
        edge.second = edge.first;
        edge.first = tmp;
    }

    // add edge
    etable+edge;
    atable+edge;

    return *this;

}

Graph &Graph::operator-(int v) {

    if (!atable.contains(v)) {
        return *this;
    }

    atable-v;
    vtable-v;

    return *this;
}

Graph &Graph::operator-(Graph::E edge) {

    if (!atable.contains(edge)) {
        return *this;
    }

    atable-edge;
    etable-edge;

    return *this;
}

int Graph::v() {
    return vtable.size();
}

int Graph::e() {
    return etable.size();
}

Graph &Graph::operator!() {
    etable.clear();
    !atable;

    return *this;
}

Graph &Graph::clearEdges() {

    atable.clearEdges();
    etable.clear();

    return *this;
}


Graph &Graph::complete() {
    NList all;

    // get all neighbors
    for (auto const& v : atable.atable) {
        all.insert(v.first);
    }

    for (auto const& v : all ) {
        for (auto const & u : all) {

            // generate ordered pairs (u,v) s.t. u < v
            if (u >= v) {
                break;
            }

            // add an edge if it isn't already in the graph. Edges already in the
            // graph are untouched to preserve coloring and embedding properties
            if ( etable.contains(E(u,v)) ) {
                operator+(E(u,v));
            }

        }

    }
    return *this;
}

Graph::Graph(const char c, int order) {

    if (c == 'K') {         // 'K' flag produces a complete graph of order given

        // generate vertices
        for (int i = 1; i <= order; i++) {
            *this+i;
        }
        complete();

    } else if (c == 'C') {  // 'C' flag produces a cycle graph of order given

        // generate vertices and edges
        for (int i = 1; i < order; i++) {
            *this+(E(i, i+1));
        }
        // generate final edge
        *this+E(1, order);

    } else {
        throw ConstructorException();
    }
}

Graph &Graph::relabelVertex(int from, int to) {

    return *this;
}

Graph &Graph::relabelAll(int start, int finish) {
    NList vertices = listVertices();

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
    std::set<int> diff1;
    std::set_difference(vertices.begin(), vertices.end(),
            new_labels.begin(), new_labels.end(),
            std::inserter(diff1, diff1.end()));

    // find new labels for ids to change
    std::set<int> diff2;
    std::set_difference(new_labels.begin(), new_labels.end(),
                        vertices.begin(), vertices.end(),
                        std::inserter(diff2, diff2.end()));

    for (auto const& id : diff1) {
        std::cout << id << ", " << *diff2.begin() << std::endl;

        //relabelVertex(id, *(diff2.begin()) );

        diff2.erase(*(diff2.begin()));
    }

    return *this;
}

std::set<int> Graph::listVertices() {
    NList vertices;

    for (auto const& v : atable.atable) {
        vertices.insert(v.first);
    }
    return vertices;
}

Graph &Graph::operator|(Graph::E edge) {

    // check that edge is in graph
    if (etable.contains(edge)) {
        throw OutOfRangeException();
    }

    // get adjacencies of v2
    NList neighbors = atable.atable[edge.first];

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
    for (auto const& v : g.atable.atable) {
        for (auto const& u : v.second) {
            (*this)+E(u, v.first);
        }
    }

    // copy
    atable = g.atable;

    return *this;
}





