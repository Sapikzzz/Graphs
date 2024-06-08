//
// Created by Jakub on 08.06.2024.
//

#include "adjacency_list.h"
#include <iostream>
#include <queue>
#include <limits>
#include <stack>

#define INF numeric_limits<int>::max()

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

void adjacency_list::dijkstra(int source, vector<int>& distances, vector<int>& parents) {
    distances.resize(V, INF);   // Initialize all distances to infinity
    parents.resize(V, -1);    // Initialize all parents to -1
    distances[source] = 0;  // Distance from source to itself is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {   // While there are vertices to be processed
        int u = pq.top().second;    // Get the vertex with the smallest distance
        pq.pop();   // Remove the vertex from the queue

        for (auto& neighbor : adjList[u]) { // Check every neighbor of u for the shortest path
            int v = neighbor.first;     // Get the neighbor's index
            int weight = neighbor.second;       // Get the weight of the edge
            int dist_v = distances[u] + weight;     // Calculate the distance from the source to v through u

            if (dist_v < distances[v]) {
                distances[v] = dist_v;
                parents[v] = u;
                pq.push(make_pair(dist_v, v));
            }
        }
    }
}

void adjacency_list::printShortestPath(int source, int dest, const vector<int>& parents) {
    if (dest == source) {
        cout << source << " ";
        return;
    }

    if (parents[dest] == -1) {
        cout << "No path from " << source << " to " << dest << endl;
        return;
    }

    stack<int> path;
    int vertex = dest;
    path.push(vertex);

    while (vertex != source) {
        vertex = parents[vertex];
        path.push(vertex);
    }

    cout << "Shortest path from " << source << " to " << dest << ": ";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}