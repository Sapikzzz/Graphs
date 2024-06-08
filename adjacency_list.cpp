//
// Created by Jakub on 08.06.2024.
//

#include "adjacency_list.h"
#include <iostream>
#include <queue>
#include <limits>
#include <stack>
#include <random>

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
    distances.resize(V, INF);
    parents.resize(V, -1);
    distances[source] = 0;

    struct Node {
        int vertex, distance;
        Node(int v, int d) : vertex(v), distance(d) {}
        bool operator>(const Node& other) const {
            return distance > other.distance;
        }
    };

    priority_queue<Node, vector<Node>, greater<Node>> minHeap;
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

bool adjacency_list::hasEdge(int u, int v) {
    for (const auto& neighbor : adjList[u]) {
        if (neighbor.first == v) {
            return true;
        }
    }
    return false;
}

void adjacency_list::fillListWithDensity(double density) {
    int maxEdges = V * (V - 1);
    int numEdges = (int)(density * maxEdges);
    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < numEdges; i++) {
        int v = gen() % V;
        int u = gen() % V;
        int weight = gen() % 20 + 1;

        if(v == u){
            i--;
        }
        else{
            addEdge(u, v, weight);
        }
    }
}