#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> nextPermutation(std::vector<int>&& nums) {
        std::next_permutation(nums.begin(), nums.end());
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
    std::cout << Solution{}.nextPermutation({1, 2, 3}) << "\n";
    std::cout << Solution{}.nextPermutation({3, 2, 1}) << "\n";
    std::cout << Solution{}.nextPermutation({1, 1, 5}) << "\n";
}