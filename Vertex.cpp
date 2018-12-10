//
// Created by hadend on 11/22/18.
//

#include "Vertex.h"

Vertex::Vertex(int num) {
    id = num;
    color = -1;
}

Vertex::Vertex() {
    color = -1;
}

void Vertex::setID(int _id) {
    id = _id;
    return;
}

