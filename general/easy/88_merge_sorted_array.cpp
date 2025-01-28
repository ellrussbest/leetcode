#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> merge(std::vector<int>&& nums1, int m,
                           std::vector<int>&& nums2, [[maybe_unused]] int n) {
        auto middle = std::next(nums1.begin(), m);
        
        auto it2 = nums2.begin();
        for(auto it = middle; it != nums1.end(); ++it)
            *it = *it2++;

        // inplace merge
        std::inplace_merge(nums1.begin(), middle, nums1.end());

        return nums1;
    }
};

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
    out << "{";
    for (char sep[]{0, ' ', 0}; const auto& s : v)
        out << sep << s, sep[0] = ',';
    out << "}";

    return out;
}

int main() {
    std::cout << Solution{}.merge({1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3) << "\n";
    std::cout << Solution{}.merge({1}, 1, {}, 0) << "\n";
    std::cout << Solution{}.merge({0}, 0, {1}, 1) << "\n";
}