#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> merge(std::vector<int>&& nums1, int m,
                           std::vector<int>&& nums2, [[maybe_unused]] int n) {
        auto last = nums1.begin() + m;

        for (const auto& num : nums2) {
            auto it = std::lower_bound(nums1.begin(), last, num);
            if (it == last)
                *it = num;
            else {
                shift(it, last);
                *it = num;
            }
            ++last;
        }

        return nums1;
    }

   private:
    template <typename BidirIt>
    void shift(BidirIt first, BidirIt last) {
        auto prev = std::prev(last);

        while (last != first) {
            *last = std::move(*prev);
            --last, --prev;
        }
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