//
// Created by hadend on 12/9/18.
//

#ifndef PITRI_VERTEXTABLE_H
#define PITRI_VERTEXTABLE_H


#include <memory>
#include <map>
#include "Vertex.h"

class map;

class VertexTable {
public:
    // mutators
    VertexTable& operator+(int vertex);
    VertexTable& operator-(int vertex);
    VertexTable& clear();

    // accessors
    Vertex& operator[](int vertex);
    bool contains(int vertex);
    int size();

private:
    std::map<int, std::shared_ptr<Vertex> > table;
};


#endif //PITRI_VERTEXTABLE_H