//
// Created by hadend on 11/20/18.
//

#ifndef PITRI_VERTEX_H
#define PITRI_VERTEX_H


#include <string>

struct Vertex {
    int color;
    std::string name;
    double x_pos;
    double y_pos;

    void set_pos(double x, double y);
};


#endif //PITRI_VERTEX_H
