#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::vector<int> rotate(std::vector<int>&& nums, int k) {
        k = (k % static_cast<int>(nums.size()));
        std::rotate(nums.rbegin(), std::next(nums.rbegin(), k), nums.rend());
        return nums;
    }
};

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
    out << "{";
    for (char sep[]{0, ' ', 0}; const auto& el : v)
        out << sep << el, sep[0] = ',';
    out << "}";

    return out;
}

int main() {
    std::cout << Solution{}.rotate({1,2,3,4,5,6,7}, 3) << "\n";
    std::cout << Solution{}.rotate({-1,-100,3,99}, 2) << "\n";
}