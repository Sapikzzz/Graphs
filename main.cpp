//
// Created by Jakub on 08.06.2024.
//
#include <iostream>
#include "adjacency_list.h"
#include "adjacency_matrix.h"
#include <limits>
#include <chrono>

#define INF numeric_limits<int>::max()

int main() {
    int vertices = 10;
    double density = 0.75;
    int source = 3;

    std::cout << "Adjacency List" << std::endl;
    // Creating adjacency list
    adjacency_list graph(vertices);
    // Filling with given density with weights range 1 - 10
    graph.fillListWithDensity(density, 10);
    graph.printGraph();
    // Initializing vectors for distances and parents for Dijkstra algorithm
    std::vector<int> distances;
    std::vector<int> parents;
    // Running Dijkstra algorithm
    graph.dijkstra(source, distances, parents);
    // Printing the shortest path from 3 to 9 with Dijkstra algorithm point to point
    std::cout << "Shortest path from 3 to 9 is: " << graph.shortestPath(3, 9) << std::endl;


    // Printing distances to every vertex
    for (int i = 0; i < distances.size(); i++) {
        if(distances[i] == std::INF){
            std::cout << "No edge from " << source <<  " to " << i  << std::endl;
        }
        else {
            std::cout << "Distance from 3 to " << i << " is " << distances[i] << std::endl;
        }
    }

    std::cout << "------------------------------------" << std::endl;
    std::cout << "Adjacency Matrix" << std::endl;

    adjacency_matrix graph2(vertices);
    graph2.fillMatrixWithDensity(density);
    graph2.printGraph();
    std::vector<int> distances2;
    std::vector<int> parents2;
    graph2.dijkstra(source, distances2, parents2);
    std::cout << "Shortest path from 3 to 9 is: " << graph2.shortestPath(3, 9) << std::endl;

    for (int i = 0; i < distances2.size(); i++) {
        if(distances2[i] == std::INF){
            std::cout << "No edge from " << source <<  " to " << i  << std::endl;
        }
        else {
            std::cout << "Distance from 3 to " << i << " is " << distances2[i] << std::endl;
        }
    }
    return 0;
}
