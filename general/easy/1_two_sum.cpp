#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, size_t> m_map;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (auto it = m_map.find(nums[i]); it != m_map.end())
                return {static_cast<int>(it->second), static_cast<int>(i)};

            auto complement = target - nums[i];
            m_map.try_emplace(complement, i);
        }

        return {};
    }

    std::vector<int> twoSum_bruteforce(const std::vector<int>& nums,
                                       int target) {
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {static_cast<int>(i), static_cast<int>(j)};
                }
            }
        }

        return {};
    }
};

// overload stream insertion operator
std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
    out << "{";
    for (char sep[]{0, ' ', 0}; const auto& el : v)
        out << sep << el, sep[0] = ',';
    out << "}";

    return out;
}

int main() {
    std::cout << Solution{}.twoSum({2, 7, 11, 15}, 9) << "\n";
    std::cout << Solution{}.twoSum({3, 2, 4}, 6) << "\n";
    std::cout << Solution{}.twoSum({3, 3}, 6) << "\n";

    std::cout << Solution{}.twoSum_bruteforce({2, 7, 11, 15}, 9) << "\n";
    std::cout << Solution{}.twoSum_bruteforce({3, 2, 4}, 6) << "\n";
    std::cout << Solution{}.twoSum_bruteforce({3, 3}, 6) << "\n";
}