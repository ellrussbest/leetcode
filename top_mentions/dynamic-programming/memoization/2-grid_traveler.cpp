/**
 * Say that you are a traveler on a 2D grid. You begin in the top-left corner
 * and your goal is to travel to the bottom-right corner. You may only move down
 * or right
 *
 */

#include <iostream>
#include <unordered_map>
#include <string>

size_t grid_traveler_helper(int x, int y, std::unordered_map<std::string, size_t>& memo) {
    if(x == 0 || y == 0)
        return 0;

    if (x == 1 || y == 1) 
        return 1;

    auto key = std::to_string(x) + ',' + std::to_string(y);
    if (auto it = memo.find(key); it != memo.end()) 
        return it->second;

    auto res = grid_traveler_helper(x - 1, y, memo) +
               grid_traveler_helper(x, y - 1, memo);
    memo.emplace(std::move(key), res);
    return res;
}

size_t grid_traveler(int x, int y) {
    std::unordered_map<std::string, size_t> memo;
    return grid_traveler_helper(x, y, memo);
}

int main() {
    std::cout << grid_traveler(3, 3) << "\n";
    std::cout << grid_traveler(2, 3) << "\n";
    std::cout << grid_traveler(2, 2) << "\n";
    std::cout << grid_traveler(18, 18) << "\n";
}