/**
 * Say that you are a traveler on a 2D grid. You begin in the top-left corner
 * and your goal is to travel to the bottom-right corner. You may only move down
 * or right
 *
 * hint grid_traveler(1, 1) return 1
 */

#include <iostream>
#include <vector>

size_t grid_traveler(int x, int y) {
    size_t X = static_cast<size_t>(x);
    size_t Y = static_cast<size_t>(y);

    std::vector<std::vector<size_t>> dp{X + 1, std::vector<size_t>(Y + 1, 0)};
    dp[1][1] = 1;

    for (auto row = dp.begin(); row != dp.end(); ++row) {
        size_t j = 0;
        for (auto col = row->begin(); col != row->end(); ++col, ++j) {
            // move right
            if (std::next(col) != row->end())
                *std::next(col) += *col;

            // move down
            if (std::next(row) != dp.end())
                std::next(row)->at(j) += *col;
        }
    }

    return dp[X][Y];
}

int main() {
    std::cout << grid_traveler(3, 3) << "\n";
    std::cout << grid_traveler(2, 3) << "\n";
    std::cout << grid_traveler(2, 2) << "\n";
    std::cout << grid_traveler(18, 18) << "\n";
}