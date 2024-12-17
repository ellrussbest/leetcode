#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int findMin(const std::vector<int>& nums) {
        const auto& first = *nums.begin();
        auto it = std::partition_point(
            std::next(nums.begin()), nums.end(),
            [first](const auto& val) { return first < val; });

        if (it == nums.end())
            return *nums.begin();
        else
            return *it;
    }
};

int main() {
    std::cout << Solution{}.findMin({3, 4, 5, 1, 2}) << "\n";
    std::cout << Solution{}.findMin({4, 5, 6, 7, 0, 1, 2}) << "\n";
    std::cout << Solution{}.findMin({11, 13, 15, 17}) << "\n";
    std::cout << Solution{}.findMin({2, 1}) << "\n";
}