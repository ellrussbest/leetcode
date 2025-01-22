#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>&& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;

        for (auto i = nums.begin(); i != nums.end(); ++i) {
            if (i != nums.begin() && *std::prev(i) == *i)
                continue;

            auto left = std::next(i);
            auto right = nums.rbegin();

            while (std::distance(left, right.base()) > 1) {

                auto sum = *i + *left + *right;

                if (sum == 0) {
                    res.emplace_back(std::vector<int>{*i, *left, *right});

                    while (true) {
                        auto prev = right++;
                        if (right == nums.rend())
                            break;

                        if (*right != *prev)
                            break;
                    }

                    while (true) {
                        auto prev = left++;
                        if (left == nums.end())
                            break;

                        if (*left != *prev)
                            break;
                    }
                } else if (sum > 0)
                    ++right;
                else
                    ++left;
            }
        }

        return res;
    }
};

std::ostream& operator <<(std::ostream& out, const std::vector<std::vector<int>>& vv) {
    out << "{";
    for(char sep[]{0, ' ', 0}; const auto& v : vv) {
        out << sep << "\n\t" << "{", sep[0] = ',';
        for(char sep2[]{0, ' ', 0}; const auto& el : v) {
            out << sep2 << el, sep2[0] = ',';
        }
        out << "}";
    }
    std::cout << "\n}";
    return out;
}

int main() {
    std::cout << Solution{}.threeSum({-1,0,1,2,-1,-4}) << "\n";
    std::cout << Solution{}.threeSum({0,1,1}) << "\n";
    std::cout << Solution{}.threeSum({0,0,0}) << "\n";
}