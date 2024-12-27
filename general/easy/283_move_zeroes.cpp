#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class Solution {
   public:
    std::vector<int> moveZeroes(std::vector<int>&& nums) {
        auto first = std::find(nums.begin(), nums.end(), 0);

        if(first != nums.end())
            for (auto j = first; ++j != nums.end();) {
                if (!(*j == 0)) 
                    std::iter_swap(first++, j);
            }

        return nums;
    }
};

// overload stream insertion operator
std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
    out << "{";
    for (char sep[]{0, ' ', 0}; const auto& el : v)
        out << sep << el, sep[0] = ',';
    out << "}";

    return out;
}

int main() {
    std::cout << Solution{}.moveZeroes({0, 1, 0, 3, 12}) << "\n";
    std::cout << Solution{}.moveZeroes({0}) << "\n";
    std::cout << Solution{}.moveZeroes({1}) << "\n";
}