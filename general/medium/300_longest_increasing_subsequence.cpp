#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(const std::vector<int>& nums) {
        std::vector<int> v;

        for(const auto& num : nums) {
            auto it = std::lower_bound(v.begin(), v.end(), num);
            if(it == v.end())
                v.emplace_back(num);
            else
                *it = num;
        }
        
        return static_cast<int>(v.size());
    }
};


int main() {
    std::cout << Solution{}.lengthOfLIS({10,9,2,5,3,7,101,18}) << "\n";
    std::cout << Solution{}.lengthOfLIS({0,1,0,3,2,3}) << "\n";
    std::cout << Solution{}.lengthOfLIS({7,7,7,7,7,7,7}) << "\n";
}