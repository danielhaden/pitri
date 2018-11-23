//
// Created by hadend on 11/22/18.
//

#ifndef PITRI_VERTEX_H
#define PITRI_VERTEX_H


#include <string>

struct Vertex {
    Vertex() {};
    Vertex(int num);

    int id;
    std::string tag;

    int color;
    double x;
    double y;

    Vertex& operator= (const Vertex& rhs);
};


#endif //PITRI_VERTEX_H
