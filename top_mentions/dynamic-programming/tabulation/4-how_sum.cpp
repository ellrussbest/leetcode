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
#include <vector>
#include <optional>
#include <algorithm>

std::vector<size_t> how_sum(int target, const std::vector<size_t>& numbers) {
    size_t N = static_cast<size_t>(target);
    std::vector<std::optional<std::vector<size_t>>> dp(N + 1, std::nullopt);

    dp[0] = std::vector<size_t>{};

    for(size_t i = 0; i < dp.size(); ++i) {
        for(const auto& num : numbers) {
            if(i+num < dp.size() && dp[i]) {
                const auto& cur = *dp[i];
                auto& dest = dp[i+num];

                dest = std::vector<size_t>{};
                std::copy(cur.begin(), cur.end(), std::back_inserter(*dest));
                dest->emplace_back(num);
            }
        }
    }

    if(dp[N])
        return *dp[N];
    return {};
}

std::ostream& operator<<(std::ostream& out, std::vector<size_t> v) {
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