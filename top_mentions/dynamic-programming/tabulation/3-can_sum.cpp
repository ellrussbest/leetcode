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
#include <vector>

bool can_sum(int target, const std::vector<size_t> v) {
    size_t N = static_cast<size_t>(target);
    std::vector<bool> dp(N + 1, false);

    dp[0] = true;

    for(size_t i = 0; i < dp.size(); ++i) {
        for(auto j = v.begin(); j != v.end(); ++j) {
            if(i + *j < dp.size() && dp[i] == true)
                dp[i + *j] = true;
        }
    }

    return dp[N];
}

int main() {
    std::cout << std::boolalpha;
    std::cout << can_sum(7, {5, 3, 4}) << "\n";
    std::cout << can_sum(7, {5, 3, 4, 7}) << "\n";
    std::cout << can_sum(7, {2, 4}) << "\n";
    std::cout << can_sum(8, {2, 3, 5}) << "\n";
    std::cout << can_sum(300, {7, 14}) << "\n";
}