#include <vector>
#include <iostream>
#include <cmath>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>&& nums) {
        std::vector<int> res;

        for(size_t i = 0; i < nums.size(); ++i) {
            int idx = std::abs(nums[i]) - 1;
            size_t N = static_cast<size_t>(idx);

            if(nums[N] > 0)
                nums[N] *= -1;
        }

        for(size_t i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0)
                res.emplace_back(static_cast<int>(i+1));
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
    std::cout << Solution{}.findDisappearedNumbers({4,3,2,7,8,2,3,1}) << "\n";
    std::cout << Solution{}.findDisappearedNumbers({1, 1}) << "\n";
}