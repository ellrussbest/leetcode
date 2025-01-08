#include <vector>
#include <iostream>

class Solution {
public:
    int firstMissingPositive(std::vector<int>&& nums) {
        int res = static_cast<int>(nums.size()) + 1;

        for(auto& num : nums) {
            if(num <= 0)
                num = res;
        }

        for(size_t i = 0; i < nums.size(); ++i) {
            int idx = std::abs(nums[i]) - 1;
            size_t N = static_cast<size_t>(idx);

            if(N < nums.size() && nums[N] > 0)
                nums[N] *= -1;
        }

        for(size_t i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0)
                return static_cast<int>(i) + 1;
        }


        return res;
    }
};

int main() {
    std::cout << Solution{}.firstMissingPositive({1,2,0}) << "\n";
    std::cout << Solution{}.firstMissingPositive({3,4,-1,1}) << "\n";
    std::cout << Solution{}.firstMissingPositive({7,8,9,11,12}) << "\n";
}