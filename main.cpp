//
// Created by Jakub on 08.06.2024.
//
#include <iostream>
#include "adjacency_list.h"
#include "adjacency_matrix.h"

int main() {
    adjacency_list graph(5);
    adjacency_matrix graph2(5);

    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 5);
    graph.addEdge(3, 4, 6);
    graph.addEdge(4, 0, 7);
    graph.addEdge(4, 1, 9);

    graph.printGraph();

    vector<int> distances;
    vector<int> parents;
    graph.dijkstra(3, distances, parents);

    for (int i = 0; i < distances.size(); i++) {
        cout << "Distance from 3 to " << i << " is " << distances[i] << endl;
    }

    graph.printShortestPath(3, 2, parents);

    graph2.addEdge(0, 1, 1);
    graph2.addEdge(0, 2, 2);
    graph2.addEdge(1, 2, 3);
    graph2.addEdge(1, 3, 4);
    graph2.addEdge(2, 3, 5);
    graph2.addEdge(3, 4, 6);
    graph2.addEdge(4, 0, 7);
    graph2.addEdge(4, 1, 8);

    graph2.printGraph();

    vector<int> distances2;
    vector<int> parents2;
    graph2.dijkstra(3, distances2, parents2);

    for (int i = 0; i < distances2.size(); i++) {
        cout << "Distance from 3 to " << i << " is " << distances2[i] << endl;
    }

    graph2.printShortestPath(3, 2, parents2);
    return 0;
}
