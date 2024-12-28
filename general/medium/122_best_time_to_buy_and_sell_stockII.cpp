#include <iostream>
#include <vector>

class Solution {
   public:
    int maxProfit(const std::vector<int>& prices) {
        int total_profit = 0;
        int profit = 0;

        for (auto i = prices.begin(), j = i; ++j != prices.end();) {
            if (*j - *i < profit) {
                i = j;
                total_profit += profit;
                profit = 0;
            } else
                profit = std::max(profit, *j - *i);
        }

        return total_profit + profit;
    }
};

int main() {
    std::cout << Solution{}.maxProfit({7, 1, 5, 3, 6, 4}) << "\n";
    std::cout << Solution{}.maxProfit({1, 2, 3, 4, 5}) << "\n";
    std::cout << Solution{}.maxProfit({7, 6, 4, 3, 1}) << "\n";
}