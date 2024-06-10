//
// Created by Jakub on 08.06.2024.
//

#include "adjacency_matrix.h"
#include <iostream>
#include <queue>
#include <limits>
#include <stack>
#include <random>

#define INF numeric_limits<int>::max()


adjacency_matrix::adjacency_matrix(int V) {
    this->V = V;
    adjMatrix.resize(V, std::vector<int>(V, 0));
}

void adjacency_matrix::addEdge(int u, int v, int weight) {
    if (u != v) {
        adjMatrix[u][v] = weight;
    }
    else {
        std::cout << "Giving self weight" << std::endl;
    }
}

int adjacency_matrix::getWeight(int u, int v) {
    return adjMatrix[u][v];
}

void adjacency_matrix::printGraph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void adjacency_matrix::dijkstra(int source, std::vector<int>& distances, std::vector<int>& parents) {
    distances.resize(V, std::INF);
    parents.resize(V, -1);
    distances[source] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] != 0) {
                int weight = adjMatrix[u][v];
                int dist_v = distances[u] + weight;

                if (dist_v < distances[v]) {
                    distances[v] = dist_v;
                    parents[v] = u;
                    pq.push(std::make_pair(dist_v, v));
                }
            }
        }
    }
}

void adjacency_matrix::fillMatrixWithDensity(double density) {
    int maxEdges = V * (V - 1);
    int numEdges = (int)(density * maxEdges);
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        do {
            u = gen() % V;
            v = gen() % V;
        } while (u == v || adjMatrix[u][v] != 0);

        int weight = gen() % 20 + 1;    // 1-20
        adjMatrix[u][v] = weight;
    }
}

int adjacency_matrix::shortestPath(int src, int dest) {
    std::vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] != 0) {
                int alt = dist[u] + adjMatrix[u][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    pq.push(std::make_pair(dist[v], v));
                }
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        return -1; // No path exists
    }

    return dist[dest];
}