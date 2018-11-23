//
// Created by hadend on 11/22/18.
//

#ifndef PITRI_VERTEX_H
#define PITRI_VERTEX_H


#include <string>

struct Vertex {
    int id;
    std::string tag;

    int degree;

    int color;
    double x;
    double y;

    friend bool operator< (const Vertex &lhs, const Vertex &rhs);
    friend bool operator> (const Vertex &lhs, const Vertex &rhs);
};


#endif //PITRI_VERTEX_H
