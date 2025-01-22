#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>&& nums) {
        auto it = std::unique(nums.begin(), nums.end());
        return static_cast<int>(std::distance(nums.begin(), it));
    }
};

int main() {
    std::cout << Solution{}.removeDuplicates({1,1,2}) << "\n";
    std::cout << Solution{}.removeDuplicates({0,0,1,1,1,2,2,3,3,4}) << "\n";
}