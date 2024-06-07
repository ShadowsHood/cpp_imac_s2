#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include "graph.hpp"

int main() {
    std::cout << "TD 07 - Ex 01" << std::endl;

    // std::string user_str {};
    // std::cout << "Entrez une phrase à hacher : ";
    // std::getline(std::cin, user_str);

    // std::vector<std::vector<float>> const adjacencyMatrix {
    //     {0,1,0,0,2},
    //     {0,0,2,4,0},
    //     {0,0,0,1,0},
    //     {0,0,0,0,6},
    //     {0,0,0,0,0},
    //     {5,0,0,0,0},
    // };

    // Graph::WeightedGraph graphByAdjacencyMatrix {Graph::build_from_adjacency_matrix(adjacencyMatrix)};
    // Graph::WeightedGraph graphByVertex {};
    // graphByVertex.add_directed_edge(0,1,1.0f);
    // graphByVertex.add_directed_edge(0,4,2.0f);
    // graphByVertex.add_directed_edge(1,2,2.0f);
    // graphByVertex.add_directed_edge(1,3,4.0f);
    // graphByVertex.add_directed_edge(2,3,1.0f);
    // graphByVertex.add_directed_edge(3,4,6.0f);
    // graphByVertex.add_vertex(4);
    // graphByVertex.add_directed_edge(5,0,5.0f);

    // std::cout << "Comparaison graph matrix/vertex :";
    // graphByVertex == graphByAdjacencyMatrix ? std::cout<<"True" : std::cout<<"False";
    // std::cout << std::endl;



    std::vector<std::vector<float>> const adjacencyMatrixDijkstra {
        {0,1,5,2,0,0},
        {0,0,4,5,0,0},
        {0,0,0,0,3,4},
        {0,0,2,0,5,0},
        {0,0,0,0,0,3},
        {0,0,0,0,0,0},
    };
    Graph::WeightedGraph graphDijkstra {Graph::build_from_adjacency_matrix(adjacencyMatrixDijkstra)};
    std::unordered_map<int, std::pair<float, int>> paths_AtoE {dijkstra(graphDijkstra, 0, 4)};
    //Debug paths
    // for (auto &&i : paths_AtoE) {
    //     std::cout << i.first << ", previous : " << i.second.second << ", distance : " << i.second.first << std::endl;
    // }
    std::cout << "Le plus court chemin pour aller du point A(0) au point E(4) est de " << paths_AtoE.find(4)->second.first << " en passant par : ";    
    display_path_form_end(paths_AtoE, 0, 4);
    std::cout << std::endl;


    std::unordered_map<int, std::pair<float, int>> paths_BtoF {dijkstra(graphDijkstra, 1, 5)};
    std::cout << "Le plus court chemin pour aller du point B(1) au point F(5) est de " << paths_BtoF.find(5)->second.first << " en passant par : ";    
    display_path_form_end(paths_BtoF, 1, 5);
    std::cout << std::endl;
    
    

    return 0;
}