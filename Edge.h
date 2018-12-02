//
// Created by hadend on 12/2/18.
//

#ifndef PITRI_EDGE_H
#define PITRI_EDGE_H


struct Edge {
    Edge(int v1, int v2);

    int v1;
    int v2;
    bool directed;
    int color;
    int direction;

};


#endif //PITRI_EDGE_H
