//
// Created by Jakub on 08.06.2024.
//

#ifndef GRAPHS_ADJACENCY_LIST_H
#define GRAPHS_ADJACENCY_LIST_H

#include <vector>
#include <list>
#include <utility>

using namespace std;

class adjacency_list {
private:
    int V; // Number of vertices
    vector<list<pair<int, int>>> adjList; // Adjacency List

public:
    adjacency_list(int V); // Constructor
    void addEdge(int u, int v, int weight);
    list<pair<int, int>> getAdjacentVertices(int v);
    void printGraph();
};


#endif //GRAPHS_ADJACENCY_LIST_H
