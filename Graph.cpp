//
// Created by hadend on 12/1/18.
//

#include <iostream>
#include "Graph.h"


Graph::Graph() {
    order = 0;
    multiedges = false;
    loops = false;
    simple = true;
}

Graph::Graph(bool simple) : simple(simple) {

}

Graph::Graph(std::map<int, std::list<int> > al) {
    for (auto const& x : al) {
        int u = x.first;

        for (auto const& i : x.second) {
            int v = i;

            if (u == v) {
                loops = true;
            }

            adjacency_list+(u,v);
        }
    }
}
