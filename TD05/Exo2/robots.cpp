#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

void console_log_int(int num) {std::cout << num << std::endl;}
void console_log_str(std::string str) {std::cout << str << std::endl;}
int random(int const& min, int const& max){return rand() % max + 1 + min;}

std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 4);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes) {
    std::unordered_map<std::string, std::vector<float>> fixesByRobots {};
    for (std::pair<std::string, float> repair : robots_fixes) {
        auto robotName {fixesByRobots.find(repair.first)};
        if (robotName != fixesByRobots.end()) {
            robotName->second.push_back(repair.second);
        } else {
            std::vector<float> firstRepair {repair.second};
            fixesByRobots.insert(std::make_pair(repair.first, firstRepair));
        }
    }
    return fixesByRobots;
}

void display_robots_map(std::unordered_map<std::string, std::vector<float>> const& liste) {
    for (auto robot : liste) {
        std::cout <<"Liste des réparations pour le robot "<< robot.first <<" :"<< std::endl;
        for (float repair : robot.second) {
            std::cout << repair << ", ";
        }
        std::cout << std::endl;
    }
}

float float_sum(std::vector<float> const& numbers) {
    float sum {0.0f};
    for(float num : numbers) sum+=num;
    return sum;
}

void display_robots_cost(std::unordered_map<std::string, std::vector<float>> const& liste) {
    for (auto robot : liste) {
        std::cout <<"Les reparations pour le robot "<< robot.first <<" ont coute : "<< float_sum(robot.second) << std::endl;
    }
}