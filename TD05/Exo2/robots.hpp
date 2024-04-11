# pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

void console_log_int(int num);
void console_log_str(std::string str);
int random(int const& min, int const& max);

std::string random_name(size_t size);
std::vector<std::pair<std::string, float>> get_robots_fix(size_t size);
std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes);
void display_robots_map(std::unordered_map<std::string, std::vector<float>> const& liste);
void display_robots_cost(std::unordered_map<std::string, std::vector<float>> const& liste);