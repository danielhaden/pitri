//
// Created by hadend on 12/9/18.
//

#ifndef PITRI_EDGETABLE_H
#define PITRI_EDGETABLE_H


#include <map>
#include <memory>
#include <set>
#include "Edge.h"

class EdgeTable {
public:
    typedef std::pair<int, int> E;
    typedef std::set< std::shared_ptr<Edge> > pointer_set;

    // mutators
    EdgeTable& operator+(E edge);
    EdgeTable& operator-(E edge);
    EdgeTable& clear();
    EdgeTable& relabel(std::shared_ptr<Edge> e_ptr, E edge);

    // accessors
    Edge& operator[](E edge);
    pointer_set operator[](int vertex);
    std::map<std::pair<int,int>, std::shared_ptr<Edge> >& getTable();

    EdgeTable& operator=(const EdgeTable& rhs);

    bool contains(E edge);
    int size();

private:
    std::map<std::pair<int,int>, std::shared_ptr<Edge> > table;
};


#endif //PITRI_EDGETABLE_H
