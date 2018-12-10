//
// Created by hadend on 12/9/18.
//

#ifndef PITRI_EDGETABLE_H
#define PITRI_EDGETABLE_H


#include <map>
#include <memory>
#include "Edge.h"

class EdgeTable {
    typedef std::pair<int, int> E;

public:
    // mutators
    EdgeTable& operator+(E edge);
    EdgeTable& operator-(E edge);

    // accessors
    bool contains(E edge);
    int size();

private:
    std::map<std::pair<int,int>, std::shared_ptr<Edge> > table;


};


#endif //PITRI_EDGETABLE_H
