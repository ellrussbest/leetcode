#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class Solution {
   public:
    int maxProfit(const std::vector<int>& prices) {
        auto max_profit = 0;

        for (auto i = prices.begin(), j = i; ++j != prices.end();) {
            if (auto profit = *j - *i; profit < 0)
                i = j;
            else
                max_profit = std::max(max_profit, profit);
        }

        return max_profit;
    }
};

int main() {
    std::cout << Solution{}.maxProfit({7, 1, 5, 3, 6, 4}) << "\n";
    std::cout << Solution{}.maxProfit({7, 6, 4, 3, 1}) << "\n";
}