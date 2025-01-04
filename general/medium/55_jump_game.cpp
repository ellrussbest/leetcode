#include <vector>
#include <iostream>

class Solution {
public:
    bool canJump(const std::vector<int>& nums) {
        if(nums.size() == 1) return true;

        auto bound = *nums.begin();

        for(int i = 1; i < static_cast<int>(nums.size()); ++i) {
            if(i > bound)
                return false;
            bound = std::max(bound, i + *std::next(nums.begin(), i));
        }

        return true;
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.canJump({2,3,1,1,4}) << "\n";
    std::cout << Solution{}.canJump({3,2,1,0,4}) << "\n";
}