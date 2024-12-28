#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    bool containsDuplicate(std::vector<int>&& nums) {
        std::sort(nums.begin(), nums.end());
        auto it = std::unique(nums.begin(), nums.end());
        return it != nums.end();
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.containsDuplicate({1, 2, 3, 1}) << "\n";
    std::cout << Solution{}.containsDuplicate({1, 2, 3, 4}) << "\n";
    std::cout << Solution{}.containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2})
              << "\n";
}