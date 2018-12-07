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



Graph &Graph::operator+(int v) {

    if (atable.contains(v)) {
        return *this;
    }

    atable+v;
    vtable.insert( std::pair<int, std::unique_ptr<Vertex> >(v, std::unique_ptr<Vertex>(new Vertex(v))));
    return *this;

}

std::ostream &operator<<(std::ostream &stream, const Graph &g) {
    std::cout << g.atable;
    return stream;
}

Graph &Graph::operator+(Graph::E edge) {

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
    etable.insert(EEntry(edge, std::shared_ptr<Edge>(new Edge(edge.first, edge.second))));
    atable+edge;

    return *this;

}

Graph &Graph::operator-(int v) {

    if (!atable.contains(v)) {
        return *this;
    }

    atable-v;
    vtable.erase(v);

    return *this;
}

Graph &Graph::operator-(Graph::E edge) {

    if (!atable.contains(edge)) {
        return *this;
    }

    atable-edge;
    etable.erase(edge);

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
    _rebuildEtable();

    return *this;
}

Graph &Graph::clearEdges() {

    for( auto const& e : etable) {
        atable-(e.first);
        etable.erase(e.first);
    }
    return *this;
}

Graph::VTable &Graph::_rebuildVtable() {
    NList vertices;

    for( auto const& v : vertices) {
        vertices.insert(v);
    }

    vtable.clear();
    for( auto const& v : vertices) {
        vtable.insert(std::pair<int, std::unique_ptr<Vertex> >(v, std::unique_ptr<Vertex>(new Vertex(v))));
    }

    return vtable;
}

Graph::ETable &Graph::_rebuildEtable() {

    etable.clear();


    for( auto const& v : atable.atable) {

        for( auto const& u : atable.atable[v.first]) {
            E e(u, v.first);

            if (v.first < u) {
                continue;
            }
            etable.insert(std::pair<E, std::unique_ptr<Edge> >(e, std::unique_ptr<Edge>(new Edge(e.first, e.second))));
        }
    }
    return etable;
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
            if ( etable.find(std::pair<int,int>(u,v)) == etable.end() ) {
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
    NList neighbors = atable.atable[from];

    // update the adjacency table (error checking occurs here)
    atable.relabel(from, to);

    // update the vertex table
    vtable[from]->id = to;
    vtable.insert(VEntry(to, vtable[from]));
    vtable.erase(from);

    // update the edge table
    for (auto const& n : neighbors) {

        // update edge object
        std::shared_ptr<Edge> ptr;
        ptr = etable[E(std::min(from, n), std::max(from, n))];
        ptr->move(from, to);

        // update etable and delete old entry
        etable.insert(EEntry(E( std::min(to, n), std::max(to, n) ), ptr));
        etable.erase(std::pair<int, int>( std::min(to, n), std::max(to, n) ));
    }
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
    if (etable.find(edge) == etable.end()) {
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


