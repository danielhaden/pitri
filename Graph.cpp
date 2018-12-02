//
// Created by hadend on 12/1/18.
//

#include <iostream>
#include "Graph.h"
#include "LoopException.h"
#include "MultiedgeException.h"

typedef std::pair<int, int> E;   // undirected edge typedef

Graph::Graph() {
    order = 0;
    multiedges = false;
    loops = false;
    simple = true;
}

Graph::Graph(bool simple) : simple(simple) {

}

Graph::Graph(std::map<int, std::list<int> > al) {

    for (auto const &x : al) {
        int u = x.first;

        for (auto const &i : x.second) {
            int v = i;


            if (u == v) {
                throw LoopException();
            }

            adjacency_list + E(u, v);
        }
    }

}

int Graph::size() {
    return adjacency_list.size;
}

std::ostream &operator<<(std::ostream &stream, const Graph &g) {
    std::cout << g.adjacency_list;
    return stream;
}

AdjacencyList &Graph::getAdjacencyList() {
    return adjacency_list;
}
