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
    int vertices = 50;
    double density = 1;
    int source = 3;



    //graph.printGraph();
//    std::vector<int> timesList;
//        adjacency_list graph(vertices);
for(int i = 0; i < 5; i++) {
    adjacency_list graph(vertices);
    graph.fillListWithDensity(density, 20);
//        std::vector<int> distances;
//        std::vector<int> parents;
    auto start = std::chrono::high_resolution_clock::now();
//        graph.dijkstra(source, distances, parents);
    graph.shortestPath(3, 86);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              <<  std::endl;
}
//    std::cout << "Shortest path from 3 to 86 is: " << graph.shortestPath(3, 86) << std::endl;
//    graph.printGraph();


//    for (int i = 0; i < distances.size(); i++) {
//        if(distances[i] == INF){
//            std::cout << "No edge from " << source <<  " to " << i  << std::endl;
//        }
//        else {
//            std::cout << "Distance from 3 to " << i << " is " << distances[i] << std::endl;
//        }
//    }


    //graph2.printGraph();
//    adjacency_matrix graph2(vertices);
//    graph2.fillMatrixWithDensity(density);
//        std::vector<int> distances2;
//        std::vector<int> parents2;
//    for (int i = 0; i < 10; i++) {
//        adjacency_matrix graph2(vertices);
//        graph2.fillMatrixWithDensity(density);
//        auto start2 = std::chrono::high_resolution_clock::now();
//        //graph2.dijkstra(3, distances2, parents2);
//        graph2.shortestPath(3, 86);
//        auto end2 = std::chrono::high_resolution_clock::now();
//        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count()
//                  << std::endl;
//}
//    for (int i = 0; i < distances2.size(); i++) {
//        if(distances2[i] == INF){
//            std::cout << "No edge from " << source <<  " to " << i  << std::endl;
//        }
//        else {
//            std::cout << "Distance from 3 to " << i << " is " << distances2[i] << std::endl;
//        }
//    }
    return 0;
}
