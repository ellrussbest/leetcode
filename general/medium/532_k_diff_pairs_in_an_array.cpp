#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int findPairs(std::vector<int>&& nums, int k) {
        std::unordered_map<int, int> m_map;

        for(const auto& num : nums) {
            auto [it, success] = m_map.try_emplace(num, 1);
            if(!success)
                ++it->second;
        }

        int count = 0;

        for(const auto& [key, val] : m_map) {
            if(k == 0) {
                if(val > 1)
                    ++count;
            }else if(m_map.find(key + k) != m_map.end())
                ++count;
        }

        return count;
    }
};

int main() {
    std::cout << Solution{}.findPairs({3,1,4,1,5}, 2) << "\n";
    std::cout << Solution{}.findPairs({1,3,1,5,4,3, 5}, 0) << "\n";
    std::cout << Solution{}.findPairs({1,2,3,4,5}, 1) << "\n";
    std::cout << Solution{}.findPairs({1,1,1,1}, 0) << "\n";
}