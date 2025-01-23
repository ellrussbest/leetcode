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
#include <optional>
#include <vector>

std::vector<size_t> best_sum(int target, const std::vector<size_t>& numbers) {
    size_t N = static_cast<size_t>(target);
    std::vector<std::optional<std::vector<size_t>>> dp(N+1, std::nullopt);

    dp[0] = std::vector<size_t>{};

    for(size_t i = 0; i < dp.size(); ++i) {
        for(const auto& num : numbers) {
            if(i+num < dp.size() && dp[i]) {
                auto& cur = *dp[i];
                auto& dest = dp[i+num];

                if(not dest or cur.size() + 1 < dest->size()) {
                    dest = std::vector<size_t>{};
                    std::copy(cur.begin(), cur.end(), std::back_inserter(*dest));
                    dest->emplace_back(num);
                }
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
    std::cout << best_sum(7, {5, 3, 4}) << "\n";
    std::cout << best_sum(7, {5, 3, 4, 7}) << "\n";
    std::cout << best_sum(7, {2, 4}) << "\n";
    std::cout << best_sum(8, {2, 3, 5}) << "\n";
    std::cout << best_sum(300, {7, 14}) << "\n";
    std::cout << best_sum(100, {1, 5, 25}) << "\n";
}