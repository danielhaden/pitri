//
// Created by hadend on 11/22/18.
//

#include "Vertex.h"

Vertex::Vertex(int num) {
    id = num;
}

Vertex &Vertex::operator=(const Vertex &rhs) {

    // self-assignment guard
    if (this == &rhs) {
        return *this;
    }

    id = rhs.id;
    tag = rhs.tag;
    color = rhs.color;
    x = rhs.x;
    y = rhs.y;

    return *this;
}

