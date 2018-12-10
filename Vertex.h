//
// Created by hadend on 11/22/18.
//

#ifndef PITRI_VERTEX_H
#define PITRI_VERTEX_H


#include <string>

struct Vertex {

    // Constructors
    Vertex();
    Vertex(int num);

    // members
    int id;
    std::string tag;
    int color;

    // mutators
    void setID(int _id);

};


#endif //PITRI_VERTEX_H
