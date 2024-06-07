#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <iterator>
#include <queue>
#include "graph.hpp"

void console_log_int(int num) {std::cout << num << std::endl;}
void console_log_str(std::string str) {std::cout << str << std::endl;}
int random(int const& min, int const& max){return rand() % max + 1 + min;}



void Graph::WeightedGraph::add_vertex(int const id) {
    if (this->adjacency_list.find(id) != this->adjacency_list.end()) {
        std::cout << "Vertex already in graph" << std::endl;
    } else {
        std::vector<Graph::WeightedGraphEdge> list_edges {};
        this->adjacency_list.insert(std::make_pair(id, list_edges));
    }
}

void Graph::WeightedGraph::add_directed_edge(int const start, int const dest, float const weight) {
    this->add_vertex(start);
    this->add_vertex(dest);
    auto selected_path { this->adjacency_list.find(start) };
    selected_path->second.push_back({dest, weight});
}

void Graph::WeightedGraph::add_undirected_edge(int const start, int const dest, float const weight) {
    this->add_directed_edge(start,dest,weight);
    this->add_directed_edge(dest,start,weight);
}

void Graph::WeightedGraph::print_DFS(int const start) const{
    std::stack<int> waiting {};
    std::vector<int> explored {};

    waiting.push(start);
    while (!waiting.empty()) {
        int curentVertex { waiting.top() };

        std::cout << curentVertex << " ";
        explored.push_back(curentVertex);
        waiting.pop();

        for (Graph::WeightedGraphEdge path : this->adjacency_list.find(curentVertex)->second) {
            if (find(explored.begin(), explored.end(), path.to) == explored.end()) {
                waiting.push(path.to);
            }
        }
    }
}

void Graph::WeightedGraph::print_BFS(int const start) const {
    std::queue<int> waiting {};
    std::vector<int> explored {};

    waiting.push(start);
    while (!waiting.empty()) {
        int curent_node {waiting.front()};

        std::cout << curent_node << " ";
        explored.push_back(curent_node);
        waiting.pop();

        for (Graph::WeightedGraphEdge path : this->adjacency_list.find(curent_node)->second) {
            if (find(explored.begin(), explored.end(), path.to) == explored.end()) {
                waiting.push(path.to);
            }
        }
    }
}




Graph::WeightedGraph Graph::build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix) {
    Graph::WeightedGraph graph {};
    for (int i=0; i<adjacency_matrix.size(); i++) {
        for (int j=0; j<adjacency_matrix[i].size(); j++) {
            if (adjacency_matrix[i][j] != 0) {
                graph.add_directed_edge(i, j, adjacency_matrix[i][j]);
            }
        }
    }  
    return graph;
}


std::unordered_map<int, std::pair<float, int>> dijkstra(Graph::WeightedGraph const& graph, int const& start, int const end) {
    // On crée un tableau associatif pour stocker les distances les plus courtes connues pour aller du sommet de départ à chaque sommet visité
    // La clé est l'identifiant du sommet et la valeur est un pair (distance, sommet précédent)
    std::unordered_map<int, std::pair<float, int>> distances {};

    // On crée une file de priorité pour stocker les sommets à visiter
    // la pair contient la distance pour aller jusqu'au sommet et l'identifiant du sommet

    // Ce type compliqué permet d'indiquer que l'on souhaite trier les éléments par ordre croissant (std::greater) et donc les éléments les plus petits seront au début de la file (top) (Min heap)
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> to_visit {};

    // 1. On ajoute le sommet de départ à la liste des sommets à visiter avec une distance de 0 (on est déjà sur le sommet de départ)
    to_visit.push(std::make_pair(0.f, start));
    distances.insert(std::make_pair(start, std::make_pair(0.f, start)));

    // Tant qu'il reste des sommets à visiter
    while (!to_visit.empty()) {
        // 2. On récupère le sommet le plus proche du sommet de départ dans la liste de priorité to_visit
        int currentVertex { to_visit.top().second };
        float currentDistance{to_visit.top().first};
        to_visit.pop();
        // 3.Si on atteins le point d'arrivé, on s'arrête
        if (currentVertex == end) {
            return distances;
        }
        // 3. On parcoure la liste des voisins (grâce à la liste d'adjacence) du nœud courant
        for (auto path : graph.adjacency_list.find(currentVertex)->second) {
            // 4. on regarde si le nœud existe dans le tableau associatif (si oui il a déjà été visité)

            auto find_node {distances.find(path.to)};
            bool const visited {find_node == distances.end()?false:true};

             if (!visited) {
                    // 5. Si le nœud n'a pas été visité, on l'ajoute au tableau associatif en calculant la distance pour aller jusqu'à ce nœud
                    // la distance actuelle + le point de l'arrête)
                    distances.insert(std::make_pair(path.to, std::make_pair(
                        distances.find(currentVertex)->second.first + path.weight, 
                        currentVertex
                    )));

                    // 6. On ajout également le nœud de destination à la liste des nœud à visité (avec la distance également pour prioriser les nœuds les plus proches)
                    to_visit.push(std::make_pair(path.weight, path.to));

                }else {
                    // 7. Si il a déjà été visité, On test si la distance dans le tableau associatif est plus grande
                    // Si c'est le cas on à trouvé un plus court chemin, on met à jour le tableau associatif et on ajoute de nouveau le sommet de destination dans la liste à visité
                    auto& previousPathToCurrent {distances.find(path.to)->second};
                    float newDistanceToCurrent {distances.find(currentVertex)->second.first + path.weight};
                    if (previousPathToCurrent.first > newDistanceToCurrent) {
                        previousPathToCurrent = {newDistanceToCurrent, currentVertex};
                        to_visit.push(std::make_pair(newDistanceToCurrent, path.to));
                    }
                } 
        }
    }

    return distances;
}

void display_path_form_end(std::unordered_map<int, std::pair<float, int>> const& paths, int const& start, int const end) {
    int currentPrevious {end};
    std::cout << currentPrevious << " ";
    while (currentPrevious != start) {
        currentPrevious = paths.find(currentPrevious)->second.second;
        std::cout << currentPrevious << " ";
    }
}