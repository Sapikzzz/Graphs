//
// Created by Jakub on 08.06.2024.
//

#include "adjacency_list.h"
#include <iostream>

adjacency_list::adjacency_list(int V) {
    this->V = V;
    adjList.resize(V);
}

void adjacency_list::addEdge(int u, int v, int weight) {
    adjList[u].push_back(make_pair(v, weight));
}

list<pair<int, int>> adjacency_list::getAdjacentVertices(int v) {
    return adjList[v];
}

void adjacency_list::printGraph() {
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (auto it = adjList[i].begin(); it != adjList[i].end(); it++) {
            cout << it->first << "(" << it->second << ") ";
        }
        cout << endl;
    }
}