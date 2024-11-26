#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

class Solution {
   public:
    int singleNumber(const std::vector<int>& nums) {
        int res{};
        for (const auto& num : nums) res = res ^ num;
        return res;
    }

    int singleNumber_bruteforce(const std::vector<int>& nums) {
        std::set<int> m_set;

        for (const auto& num : nums) {
            if (auto it = m_set.lower_bound(num);
                it == m_set.end() || *it > num) {
                m_set.emplace_hint(it, num);
            } else {
                m_set.erase(it);
            }
        }

        return *m_set.begin();
    }
};

int main() {
    std::cout << Solution{}.singleNumber({2, 2, 1}) << "\n";
    std::cout << Solution{}.singleNumber({4, 1, 2, 1, 2}) << "\n";
    std::cout << Solution{}.singleNumber({1}) << "\n";
}

// Time Complexity: O(n)
// Space Complexity: O(1)