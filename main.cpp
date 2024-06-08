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
    int vertices = 4000;
    double density = 1;
    int source = 3;



    //graph.printGraph();
    std::vector<int> timesList;
    //for(int i = 0; i<5; i++) {
        adjacency_list graph(vertices);
        graph.fillListWithDensity(density, 20);
        std::vector<int> distances;
        std::vector<int> parents;
        auto start = std::chrono::high_resolution_clock::now();
        graph.dijkstra(source, distances, parents);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Time of list: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << "ms" << std::endl;
        //timesList.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    //}

    //for(int i = 0; i<5; i++) {
   //     std::cout << timesList[i] << std::endl;
    //

//    for (int i = 0; i < distances.size(); i++) {
//        if(distances[i] == INF){
//            std::cout << "No edge from " << source <<  " to " << i  << std::endl;
//        }
//        else {
//            std::cout << "Distance from 3 to " << i << " is " << distances[i] << std::endl;
//        }
//    }

    //graph.printShortestPath(source, 880, parents);
//
//    adjacency_matrix graph2(vertices);
//
//    graph2.fillMatrixWithDensity(density);
//
//    //graph2.printGraph();
//
//    std::vector<int> distances2;
//    std::vector<int> parents2;
//    auto start2 = std::chrono::high_resolution_clock::now();
//    graph2.dijkstra(3, distances2, parents2);
//    auto end2 = std::chrono::high_resolution_clock::now();
//    std::cout << "Time of matrix: " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << "ms" << std::endl;

//    for (int i = 0; i < distances2.size(); i++) {
//        if(distances2[i] == INF){
//            std::cout << "No edge from " << source <<  " to " << i  << std::endl;
//        }
//        else {
//            std::cout << "Distance from 3 to " << i << " is " << distances2[i] << std::endl;
//        }
//    }
//
//    graph2.printShortestPath(3, 2, parents2);
    return 0;
}
