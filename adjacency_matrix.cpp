//
// Created by Jakub on 08.06.2024.
//

#include "adjacency_matrix.h"
#include <iostream>
#include <queue>
#include <limits>
#include <stack>
#include <random>
#include <algorithm>

#define INF numeric_limits<int>::max()


adjacency_matrix::adjacency_matrix(int V) {
    this->V = V;
    adjMatrix.resize(V, vector<int>(V, 0));
}

void adjacency_matrix::addEdge(int u, int v, int weight) {
    if (u != v) {
        adjMatrix[u][v] = weight;
    }
    else {
        cout << "Giving self weight" << endl;
    }
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

void adjacency_matrix::dijkstra(int source, vector<int>& distances, vector<int>& parents) {
    distances.resize(V, INF);   // Initialize all distances to infinity
    parents.resize(V, -1);    // Initialize all parents to -1
    distances[source] = 0;  // Distance from source to itself is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {   // While there are vertices to be processed
        int u = pq.top().second;    // Get the vertex with the smallest distance
        pq.pop();   // Remove the vertex from the queue

        for (int v = 0; v < V; v++) { // Check every neighbor of u for the shortest path
            if (adjMatrix[u][v] != 0) { // If there is an edge between u and v
                int weight = adjMatrix[u][v];       // Get the weight of the edge
                int dist_v = distances[u] + weight;     // Calculate the distance from the source to v through u

                if (dist_v < distances[v]) {
                    distances[v] = dist_v;
                    parents[v] = u;
                    pq.push(make_pair(dist_v, v));
                }
            }
        }
    }
}

void adjacency_matrix::printShortestPath(int source, int dest, const vector<int>& parents) {
    stack<int> path;
    int current = dest;

    while (current != source) {
        path.push(current);
        current = parents[current];
    }
    path.push(source);

    cout << "Shortest path from " << source << " to " << dest << " is: ";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

void adjacency_matrix::fillMatrixWithDensity(double density) {
    int maxEdges = V * (V - 1); // Formula for maximum number of edge in graph
    int numEdges = (int)(density * maxEdges);
    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        do {
            u = gen() % V;
            v = gen() % V;
        } while (u == v || adjMatrix[u][v] != 0);

        int weight = gen() % 10 + 1; // Random weight between 1 and 10
        adjMatrix[u][v] = weight;
    }
}