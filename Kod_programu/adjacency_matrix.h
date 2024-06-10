//
// Created by Jakub on 08.06.2024.
//

#ifndef GRAPHS_ADJACENCY_MATRIX_H
#define GRAPHS_ADJACENCY_MATRIX_H

#include <vector>

class adjacency_matrix {
private:
    int V;
    std::vector<std::vector<int>> adjMatrix;

public:
    adjacency_matrix(int V);
    void addEdge(int u, int v, int weight);
    int getWeight(int u, int v);
    void printGraph();
    void dijkstra(int source, std::vector<int>& distances, std::vector<int>& parents);
    void fillMatrixWithDensity(double density);
    int shortestPath(int src, int dest);
};

#endif //GRAPHS_ADJACENCY_MATRIX_H
