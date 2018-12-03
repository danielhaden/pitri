//
// Created by hadend on 12/1/18.
//

#include <iostream>
#include "Graph.h"
#include "LoopException.h"
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
    etable.insert(std::pair<E, std::unique_ptr<Edge> >(edge, std::unique_ptr<Edge>(new Edge(edge.first, edge.second))));
    atable+(edge);

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
