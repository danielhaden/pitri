//
// Created by hadend on 12/1/18.
//

#include "Graph.h"

bool Graph::simple() {
    if ((loops) | (multiedges)) {
        return false;
    }
    return true;
}
