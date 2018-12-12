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
    VertexTable& relabel(int from, int to);

    VertexTable& operator=(const VertexTable& rhs);

    // accessors
    Vertex& operator[](int vertex);
    bool contains(int vertex);
    int size() const;
    std::map<int, std::shared_ptr<Vertex> >& getTable();

private:
    std::map<int, std::shared_ptr<Vertex> > table;
};


#endif //PITRI_VERTEXTABLE_H
