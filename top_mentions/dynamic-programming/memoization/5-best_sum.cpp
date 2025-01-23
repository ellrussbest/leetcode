/**
 *
 * Write a function `best_sum(target, numbers)` that takes in a target sum and
 * an array of numbers as arguments. The function should return an array
 * containing the shortest combination of numbers that add up exactly the target
 * sum.
 *
 * If there is a tie for the shortest combination, you may return any one of the
 * shortest.
 */

#include <iostream>
#include <unordered_map>
#include <optional>
#include <vector>

std::optional<std::vector<int>> best_sum_helper(int target, const std::vector<int>& numbers,
                                                std::unordered_map<int, std::optional<std::vector<int>>>& memo) {

    if (target == 0) 
        return std::vector<int>{};
    if (target < 0) 
        return {};

    if (auto it = memo.find(target); it != memo.end()) 
        return it->second;

    std::optional<std::vector<int>> res{};

    for (const auto& num : numbers) {
        auto temp = best_sum_helper(target - num, numbers, memo);
        if (temp && (!res || temp->size() + 1 < res->size())) {
            temp->emplace_back(num);
            res = temp;
        }
    }

    memo.emplace(target, res);
    return res;
}

std::vector<int> best_sum(int target, const std::vector<int>& numbers) {
    std::unordered_map<int, std::optional<std::vector<int>>> memo;
    auto res = best_sum_helper(target, numbers, memo);
    if (res) 
        return *res;
    return {};
}

std::ostream& operator<<(std::ostream& out, std::vector<int> v) {
    out << "{";
    for (char sep_2[]{0, ' ', 0}; const auto& el : v)
        out << sep_2 << el, sep_2[0] = ',';
    out << "}";
    return out;
}

int main() {
    std::cout << best_sum(7, {5, 3, 4}) << "\n";
    std::cout << best_sum(7, {5, 3, 4, 7}) << "\n";
    std::cout << best_sum(7, {2, 4}) << "\n";
    std::cout << best_sum(8, {2, 3, 5}) << "\n";
    std::cout << best_sum(300, {7, 14}) << "\n";
    std::cout << best_sum(100, {1, 5, 25}) << "\n";
}