//
// Created by hadend on 11/22/18.
//

#include "Vertex.h"

bool operator< (const Vertex &lhs, const Vertex &rhs) {
    if (lhs.id < rhs.id) {
        return true;

    } else {
        return false;
    }
}

bool operator>(const Vertex &lhs, const Vertex &rhs) {
    if (lhs.id > rhs.id) {
        return true;

    } else {
        return false;
    }
}
