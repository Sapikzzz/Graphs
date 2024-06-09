//
// Created by Jakub on 08.06.2024.
//

#include "adjacency_list.h"
#include <iostream>
#include <queue>
#include <limits>
#include <stack>
#include <random>
#include <set>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>


#define INF numeric_limits<int>::max()

adjacency_list::adjacency_list(int V) {
    this->V = V;
    adjList.resize(V);
}

void adjacency_list::addEdge(int u, int v, int weight) {
    adjList[u].push_back(std::make_pair(v, weight));
}

void adjacency_list::printGraph() {
    for (int i = 0; i < V; i++) {
        std::cout << i << " -> ";
        for (auto it = adjList[i].begin(); it != adjList[i].end(); it++) {
            std::cout << it->first << "(" << it->second << ") ";
        }
        std::cout << std::endl;
    }
}

void adjacency_list::dijkstra(int source, std::vector<int>& distances, std::vector<int>& parents) {
    distances.resize(V, std::INF);
    parents.resize(V, -1);
    distances[source] = 0;

    struct Node {
        int vertex, distance;
        Node(int v, int d) : vertex(v), distance(d) {}
        bool operator>(const Node& other) const {
            return distance > other.distance;
        }
    };

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> minHeap;
    minHeap.push(Node(source, 0));

    while (!minHeap.empty()) {
        int u = minHeap.top().vertex;
        minHeap.pop();

        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            int dist_v = distances[u] + weight;

            if (dist_v < distances[v]) {
                distances[v] = dist_v;
                parents[v] = u;
                minHeap.push(Node(v, dist_v));
            }
        }
    }
}

void adjacency_list::printShortestPath(int source, int dest, const std::vector<int>& parents) {
    if (dest == source) {
        std::cout << source << " ";
        return;
    }

    if (parents[dest] == -1) {
        std::cout << "No path from " << source << " to " << dest << std::endl;
        return;
    }

    std::stack<int> path;
    int vertex = dest;
    path.push(vertex);

    while (vertex != source) {
        vertex = parents[vertex];
        path.push(vertex);
    }

    std::cout << "Shortest path from " << source << " to " << dest << ": ";
    while (!path.empty()) {
        std::cout << path.top() << " ";
        path.pop();
    }
    std::cout << std::endl;
}

void adjacency_list::fillListWithDensity(double density, int maxWeight) {
    int maxEdges = V * (V - 1); // Max edges for directed graph
    int targetEdges = static_cast<int>(density * maxEdges);

    srand(time(0)); // Seed for random number generation

    int currentEdges = 0;
    std::set<std::pair<int, int>> existingEdges;

    while (currentEdges < targetEdges) {
        int u = rand() % V;
        int v = rand() % V;
        if (u != v) { // Avoid self-loops
            std::pair<int, int> edge = std::make_pair(u, v); // Create a pair for directed edge
            if (existingEdges.find(edge) == existingEdges.end()) {
                int weight = rand() % maxWeight + 1; // Random weight between 1 and maxWeight
                addEdge(u, v, weight);
                existingEdges.insert(edge);
                currentEdges++;
            }
        }
    }
}

int adjacency_list::shortestPath(int src, int dest) {
    std::vector<int> dist(V, INT_MAX);
    std::vector<int> prev(V, -1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[src] = 0;
    pq.push(std::make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        return -1; // No path exists
    }

    return dist[dest];
}