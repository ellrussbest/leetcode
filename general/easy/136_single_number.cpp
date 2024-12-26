#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    int singleNumber(const std::vector<int>& nums) {
        int res{};
        for (const auto& num : nums)
            res ^= num;
        return res;
    }

    int singleNumber_bruteforce(const std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (const auto& num : nums) {
            auto [it, success] = set.emplace(num);
            if (!success) set.erase(it);
        }
        return *set.begin();
    }
};

int main() {
    std::cout << Solution{}.singleNumber({2, 2, 1}) << "\n";
    std::cout << Solution{}.singleNumber({4, 1, 2, 1, 2}) << "\n";
    std::cout << Solution{}.singleNumber({1}) << "\n";
}

// Time Complexity: O(n)
// Space Complexity: O(1)