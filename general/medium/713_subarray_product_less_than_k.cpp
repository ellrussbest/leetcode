#include <iostream>
#include <vector>

class Solution {
   public:
    int numSubarrayProductLessThanK(const std::vector<int>& nums, int k) {
        if(k == 0)
            return 0;

        int count = 0;
        int product = 1;

        for(size_t i = 0, j = 0; j < nums.size(); ++j) {
            product *= nums[j];

            while(i <= j && product >= k)
                product /= nums[i++];
            
            count += static_cast<int>(j - i) + 1;
        }

        return count;
    }
};

int main() {
    std::cout << Solution{}.numSubarrayProductLessThanK({10, 5, 2, 6}, 100) << "\n";
    std::cout << Solution{}.numSubarrayProductLessThanK({1, 2, 3}, 0) << "\n";
}