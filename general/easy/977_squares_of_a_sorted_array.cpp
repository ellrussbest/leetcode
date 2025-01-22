#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>&& nums) {
        std::vector<int> res(nums.size(), 0);

        auto left = nums.begin();
        auto right = nums.rbegin();

        size_t i = res.size() - 1;
        while(std::distance(left, right.base()) > 0) {
            if(std::abs(*left) > std::abs(*right))
                res[i--] = *left * *left++;
            else
                res[i--] = *right * *right++;
        }

        return res;
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
    std::cout << Solution{}.sortedSquares({-4,-1,0,3,10}) << "\n";
    std::cout << Solution{}.sortedSquares({-7,-3,2,3,11}) << "\n";
}