#include <vector>
#include <iostream>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        if(it == nums.end() || target < *it)
            return -1;
        
        return static_cast<int>(std::distance(nums.begin(), it));
    }
};

int main() {
    std::cout << Solution{}.search({-1, 0, 3, 5, 9, 12}, 9) << "\n";
    std::cout << Solution{}.search({-1, 0, 3, 5, 9, 12}, 2) << "\n";
}