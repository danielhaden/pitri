//
// Created by hadend on 12/2/18.
//

#ifndef PITRI_EDGE_H
#define PITRI_EDGE_H


struct Edge {

    // constructors
    Edge(int _v1, int _v2);

    // methods
    Edge& move(int old_v, int new_v); // changes one vertex

    // public members
    int v1;
    int v2;
    bool directed;
    int color;
    int direction;

};


#endif //PITRI_EDGE_H
