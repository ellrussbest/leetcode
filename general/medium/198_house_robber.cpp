#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int rob(const std::vector<int>& nums) {
        std::unordered_map<size_t, int> memo;
        return rob_helper(nums, nums.size(), memo);
    }
private:
    int rob_helper(const std::vector<int>& nums, size_t idx, auto& memo) {
        if (idx == 0)
            return 0;
        if (idx == 1)
            return nums[0];

        if(auto it = memo.find(idx); it != memo.end())
            return it->second;
        
        int skip_current = rob_helper(nums, idx - 1, memo);
        int rob_current = nums[idx - 1] + rob_helper(nums, idx - 2, memo);

        memo.try_emplace(idx, std::max(rob_current, skip_current));
        return std::max(rob_current, skip_current);
    }
};

int main() {
    std::cout << Solution{}.rob({1, 2, 3, 1}) << "\n";
    std::cout << Solution{}.rob({2, 7, 9, 3, 1}) << "\n";
}
