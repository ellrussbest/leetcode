#include <vector>
#include <iostream>
#include <cmath>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>&& nums) {
        std::vector<int> res;

        for(size_t i = 0; i < nums.size(); ++i) {
            int idx = std::abs(nums[i]) - 1;
            auto N = static_cast<size_t>(idx);

            if(nums[N] < 0)
                res.emplace_back(std::abs(nums[i]));
            else
                nums[N] *= -1;
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
    std::cout << Solution{}.findDuplicates({4,3,2,7,8,2,3,1}) << "\n";
    std::cout << Solution{}.findDuplicates({1, 1, 2}) << "\n";
    std::cout << Solution{}.findDuplicates({1}) << "\n";
}