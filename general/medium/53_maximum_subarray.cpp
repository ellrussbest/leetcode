#include <iostream>
#include <vector>
#include <limits>

class Solution {
public:
    int maxSubArray(const std::vector<int>& nums) {
        int cur_sum = std::numeric_limits<int>::lowest();
        int max_sum = std::numeric_limits<int>::lowest();

        for(const auto& num : nums) {
            if(cur_sum < 0)
                cur_sum = num;
            else 
                cur_sum += num;

            max_sum = std::max(max_sum, cur_sum);
        }

        return max_sum;
    }
};

int main() {
    std::cout << Solution{}.maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) << "\n";
    std::cout << Solution{}.maxSubArray({1}) << "\n";
    std::cout << Solution{}.maxSubArray({5,4,-1,7,8}) << "\n";
    std::cout << Solution{}.maxSubArray({-1}) << "\n";
}