//
// Created by Jakub on 08.06.2024.
//

#ifndef GRAPHS_ADJACENCY_MATRIX_H
#define GRAPHS_ADJACENCY_MATRIX_H

#include <vector>

using namespace std;

class adjacency_matrix {
private:
    int V; // Number of vertices
    vector<vector<int>> adjMatrix; // Adjacency Matrix

public:
    adjacency_matrix(int V); // Constructor
    void addEdge(int u, int v, int weight);
    int getWeight(int u, int v);
    void printGraph();
    void dijkstra(int source, vector<int>& distances, vector<int>& parents);
    void printShortestPath(int source, int dest, const vector<int>& parents);
};

#endif //GRAPHS_ADJACENCY_MATRIX_H
