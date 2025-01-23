/**
 * Write a function `how_sum(target, numbers)` that takes in a target sum and an
 * array of numbers as arguments.
 *
 * The Function should return an array containing any combination of elements
 * that add up to exactly the target sum. If there is no combination that adds
 * up to the target sum, then return null.
 *
 * If there are multiple combinations possible, you may return any single one.
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <optional>

std::optional<std::vector<int>> how_sum_helper(int target, const std::vector<int>& numbers,
                                std::unordered_map<int, std::nullopt_t>& memo) {
    if(target == 0)
        return std::vector<int>{};
    if(target < 0)
        return {};

    if(auto it = memo.find(target); it != memo.end())
        return it->second;
    
    for(const auto& num : numbers) {
        auto res = how_sum_helper(target - num, numbers, memo);
        if(res) {
            res->emplace_back(num);
            return res;
        }      
    }

    memo.emplace(target, std::nullopt);
    return {};
}

std::vector<int> how_sum(int target, const std::vector<int>& numbers) {
    std::unordered_map<int, std::nullopt_t> memo;
    auto res = how_sum_helper(target, numbers, memo);
    if(res)
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
    std::cout << how_sum(7, {5, 3, 4}) << "\n";
    std::cout << how_sum(7, {5, 3, 4, 7}) << "\n";
    std::cout << how_sum(7, {2, 4}) << "\n";
    std::cout << how_sum(8, {2, 3, 5}) << "\n";
    std::cout << how_sum(300, {7, 14}) << "\n";
}