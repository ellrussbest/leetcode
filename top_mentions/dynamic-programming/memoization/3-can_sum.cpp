/**
 * Write a function `can_sum(target, numbers)` that takes in a target sum and an
 * array of numbers as arguments. The function should return a boolean
 * indicating whether or not it is possible to generate the target sum using
 * numbers from the array.
 *
 * You may use an element of the array as many times as needed.
 * You may assume that all input numbers are nonnegative.
 *
 */

#include <iostream>
#include <unordered_map>
#include <vector>

bool can_sum_helper(int target, const std::vector<int>& v,
                    std::unordered_map<int, bool>& memo) {
    if (target == 0) 
        return true;
    if(target < 0)
        return false;

    if (auto it = memo.find(target); it != memo.end()) 
        return it->second;

    for (size_t i = 0; i < v.size(); ++i) {
        auto res = can_sum_helper(target - v[i], v, memo);
        if (res) 
            return true;
    }

    memo.emplace(target, false);
    return false;
}

bool can_sum(int target, const std::vector<int> v) {
    std::unordered_map<int, bool> memo;
    return can_sum_helper(target, v, memo);
}

int main() {
    std::cout << std::boolalpha;
    std::cout << can_sum(7, {5, 3, 4}) << "\n";
    std::cout << can_sum(7, {5, 3, 4, 7}) << "\n";
    std::cout << can_sum(7, {2, 4}) << "\n";
    std::cout << can_sum(8, {2, 3, 5}) << "\n";
    std::cout << can_sum(300, {7, 14}) << "\n";
}