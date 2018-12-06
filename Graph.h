//
// Created by hadend on 12/1/18.
//

#ifndef PITRI_GRAPH_H
#define PITRI_GRAPH_H

#include "AdjacencyTable.h"
#include "Edge.h"
#include <list>
#include <memory>

class Graph {
    typedef std::pair<int, int> E;   // undirected edge typedef
    typedef std::set<int> NList;
    typedef std::map<int, std::unique_ptr<Vertex> > VTable;
    typedef std::map<std::pair<int,int>, std::unique_ptr<Edge> > ETable;

public:
    // constructors
    Graph() {};
    Graph(char c, int order);

    // vertex operators
    Graph& operator+(int v);    // adds a vertex
    Graph& operator-(int v);    // subtracts a vertex

    // edge operators
    Graph& operator+(E edge);   // adds an edge
    Graph& operator-(E edge);   // subtracts an edge
    Graph& operator!();         // produces the complement


    // graph operators
    Graph& operator=(Graph const& g);   // assignment
    Graph& operator*(Graph const& g);   // joins two graphs
    Graph& complete();                  // adds every edge to the graph
    Graph& clearEdges();                // removes every edge

    // graph accessors
    int v();            // returns the number of vertices
    int e();            // returns the number of edges


    friend std::ostream& operator<<(std::ostream& stream, const Graph& g);

private:
    AdjacencyTable atable;
    VTable vtable;
    ETable etable;

    //
    VTable& _rebuildVtable();
    ETable& _rebuildEtable();




};


#endif //PITRI_GRAPH_H
