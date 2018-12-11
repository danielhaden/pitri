//
// Created by hadend on 12/1/18.
//

#ifndef PITRI_GRAPH_H
#define PITRI_GRAPH_H

#include "AdjacencyTable.h"
#include "Edge.h"
#include "EdgeTable.h"
#include "VertexTable.h"
#include <list>
#include <memory>

class Graph {
    typedef std::pair<int, int> E;   // undirected edge typedef
    typedef std::set<int> NList;

public:
    // constructors
    Graph() = default;
    Graph(char c, int order);

    // vertex operators
    Graph& operator+(int v);                    // adds a vertex
    Graph& operator-(int v);                    // deletes a vertex
    Graph& relabelVertex(int from, int to);     // changes unique id of vertex
    Graph& relabelAll(int start, int finish);   // changes all vertex ids to new range

    // edge operators
    Graph& operator+(E edge);   // adds an edge
    Graph& operator-(E edge);   // deletes an edge
    Graph& operator!();         // produces the complement
    Graph& operator|(E edge);   // contracts edge

    // graph operators
    Graph& operator=(Graph const& g);   // assignment
    Graph& operator*(Graph const& g);   // joins two graphs
    Graph& complete();                  // adds every edge to the graph
    Graph& clearEdges();                // removes every edge

    // graph accessors
    int v();                        // returns the number of vertices
    int e();                        // returns the number of edges
    std::set<int> VertexIDSet();   // returns the set of vertex ids

    friend std::ostream& operator<<(std::ostream& stream, const Graph& g);



private:
    AdjacencyTable atable;
    VertexTable vtable;
    EdgeTable etable;

    // private methods

};


#endif //PITRI_GRAPH_H
