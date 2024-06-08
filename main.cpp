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
    int vertices = 10000;
    double density = 0.75;
    int source = 3;

    adjacency_list graph(vertices);


    graph.fillListWithDensity(density);

    //graph.printGraph();



    vector<int> distances;
    vector<int> parents;
    auto start = chrono::high_resolution_clock::now();
    graph.dijkstra(source, distances, parents);
    auto end = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;


//    for (int i = 0; i < distances.size(); i++) {
//        if(distances[i] == INF){
//            cout << "No edge from " << source <<  " to " << i  << endl;
//        }
//        else {
//            cout << "Distance from 3 to " << i << " is " << distances[i] << endl;
//        }
//    }

    //graph.printShortestPath(source, 880, parents);

    adjacency_matrix graph2(vertices);

    graph2.fillMatrixWithDensity(density);

    //graph2.printGraph();
//
//    vector<int> distances2;
//    vector<int> parents2;
//    auto start2 = chrono::high_resolution_clock::now();
//    graph2.dijkstra(3, distances2, parents2);
//    auto end2 = chrono::high_resolution_clock::now();
//    cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(end2 - start2).count() << "ms" << endl;
//
//    for (int i = 0; i < distances2.size(); i++) {
//        if(distances2[i] == INF){
//            cout << "No edge from " << source <<  " to " << i  << endl;
//        }
//        else {
//            cout << "Distance from 3 to " << i << " is " << distances2[i] << endl;
//        }
//    }
//
//    graph2.printShortestPath(3, 2, parents2);
    return 0;
}
