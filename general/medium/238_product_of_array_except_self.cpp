#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class Solution {
   public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        std::vector<int> res;

        std::vector<int> prefix_product;
        std::partial_sum(nums.begin(), nums.end(),
                         std::back_inserter<std::vector<int>>(prefix_product),
                         std::multiplies<int>{});

        std::vector<int> suffix_product;
        std::partial_sum(nums.rbegin(), nums.rend(),
                         std::back_inserter<std::vector<int>>(suffix_product),
                         std::multiplies<int>{});

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto product = prefix(prefix_product, i) * suffix(suffix_product, i);
            res.emplace_back(std::move(product));
        }

        return res;
    }

   private:
    int suffix(const std::vector<int>& suffix_product, int idx) {
        if (idx < static_cast<int>(suffix_product.size()) - 1)
            return 
                *++std::next(suffix_product.rbegin(), idx);
        return 1;
    }

    int prefix(const std::vector<int>& prefix_product, int idx) {
        size_t N = static_cast<size_t>(idx);
        if (idx > 0) 
            return prefix_product[N - 1];
        return 1;
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
    std::cout << Solution{}.productExceptSelf({1, 2, 3, 4}) << "\n";
    std::cout << Solution{}.productExceptSelf({-1, 1, 0, -3, 3}) << "\n";
}