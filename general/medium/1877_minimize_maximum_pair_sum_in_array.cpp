#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int minPairSum(std::vector<int>&& nums) {
        std::sort(nums.begin(), nums.end());

        int max = 0;
        auto left = nums.begin();
        auto right = nums.end();

        while(left != right && --right != left) 
            max = std::max(max, *left++ + *right);

        return max;
    }
};

int main() {
    std::cout << Solution{}.minPairSum({3,5,2,3}) << "\n";
    std::cout << Solution{}.minPairSum({3,5,4,2,4,6}) << "\n";
}