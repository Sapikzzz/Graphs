//
// Created by Jakub on 08.06.2024.
//

#ifndef GRAPHS_ADJACENCY_LIST_H
#define GRAPHS_ADJACENCY_LIST_H

#include <vector>
#include <list>
#include <utility>

class adjacency_list {
private:
    int V; // Number of vertices
    std::vector<std::list<std::pair<int, int>>> adjList; // Adjacency List

public:
    adjacency_list(int V); // Constructor
    void addEdge(int u, int v, int weight);
    void printGraph();
    void dijkstra(int source, std::vector<int>& distances, std::vector<int>& parents);
    void printShortestPath(int source, int dest, const std::vector<int>& parents);
    void fillListWithDensity(double density,int maxWeight);
    bool edgeExists(int u, int v);
};


#endif //GRAPHS_ADJACENCY_LIST_H
