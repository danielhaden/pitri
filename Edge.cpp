//
// Created by hadend on 12/2/18.
//

#include "Edge.h"
#include "IDCollisionException.h"

Edge::Edge(int _v1, int _v2) {
    v1 = _v1;
    v2 = _v2;
    directed = false;
}

Edge& Edge::move(int old_v, int new_v) {

    if (old_v == v1) {
        v1 = new_v;

    } else if (old_v == v2) {
        v2 = new_v;

    } else {
        throw IDCollisionException();
    }
    return *this;
}
