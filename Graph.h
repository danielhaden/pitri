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
    Graph(char c, int order);       // cycle, complete so far
    Graph(char c, int m, int n);   // complete bipartite

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
    Graph& operator=(Graph const& g);                   // assignment
    Graph& operator+(Graph const& g) const;             // adds two graphs
    Graph operator*(Graph const& g) const;              // joins two graphs
    Graph inflate(Graph const& g) const;                // inflates the graph with g
    Graph cliquesum(Graph const& g1, Graph const& g2);

    Graph& complete();                  // adds every edge to the graph
    Graph& clearEdges();                // removes every edge

    // graph accessors
    int v() const;                   // returns the number of vertices
    int e();                         // returns the number of edges
    std::set<int> getVertexIDSet();  // returns the set of vertex ids
    bool isEmbedded();               //

    friend std::ostream& operator<<(std::ostream& stream, const Graph& g);

    // graph planarity
    bool isPlanar();


    // graph coloring
    Graph& color();

private:
    AdjacencyTable atable;
    VertexTable vtable;
    EdgeTable etable;
    bool embedded;

};


#endif //PITRI_GRAPH_H
