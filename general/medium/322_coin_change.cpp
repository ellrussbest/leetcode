#include <vector>
#include <iostream>

class Solution {
public:
    int coinChange(const std::vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        
        std::vector<int> dp(static_cast<size_t>(amount+1), -1);
        dp[0] = 0;

        for(size_t i = 0; i < dp.size(); ++i) {
            if(dp[i] != -1) {
                for(const auto& coin : coins) {
                    auto idx = i + static_cast<size_t>(coin);
                    if(idx < dp.size()) {
                        if(dp[idx] == -1)
                            dp[idx] = dp[i] + 1;
                        else
                            dp[idx] = std::min(dp[idx], dp[i] + 1);
                    }
                }
            }
        }

        return dp[static_cast<size_t>(amount)];
    }
};

int main() {
    std::cout << Solution{}.coinChange({1,2,5}, 11) << "\n";
    std::cout << Solution{}.coinChange({2}, 3) << "\n";
    std::cout << Solution{}.coinChange({1}, 0) << "\n";
}