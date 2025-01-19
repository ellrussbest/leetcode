#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool canReach(std::vector<int>&& arr, int start) {
        return can_reach_helper(arr, start);
    }
private:
    bool can_reach_helper(std::vector<int>& arr, int start) {
        auto N = static_cast<size_t>(start);
        if(start < 0 || start >= static_cast<int>(arr.size()) || arr[N] < 0)
            return false;
        
        if(arr[N] == 0)
            return true;
            
        arr[N] *= -1;
        auto left = can_reach_helper(arr, start - std::abs(arr[N]));
        auto right = can_reach_helper(arr, start + std::abs(arr[N]));

        return left || right;
    }
};


int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.canReach({4,2,3,0,3,1,2}, 5) << "\n";
    std::cout << Solution{}.canReach({4,2,3,0,3,1,2}, 0) << "\n";
    std::cout << Solution{}.canReach({3,0,2,1,2}, 2) << "\n";
}