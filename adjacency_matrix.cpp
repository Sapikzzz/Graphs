//
// Created by Jakub on 08.06.2024.
//

#include "adjacency_matrix.h"
#include <iostream>

adjacency_matrix::adjacency_matrix(int V) {
    this->V = V;
    adjMatrix.resize(V, vector<int>(V, 0));
}

void adjacency_matrix::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
}

int adjacency_matrix::getWeight(int u, int v) {
    return adjMatrix[u][v];
}

void adjacency_matrix::printGraph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}