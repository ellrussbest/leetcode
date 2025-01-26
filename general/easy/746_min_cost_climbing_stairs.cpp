#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(const std::vector<int>& cost) {
        size_t N = cost.size();
        std::vector<int> dp(N + 1, -1);
        
        dp[0] = 0;
        dp[1] = 0;
        
        for (size_t i = 0; i < N; ++i) {
            if (i + 1 < dp.size()) {
                if(dp[i+1] == -1)
                    dp[i+1] = dp[i] + cost[i];
                else
                    dp[i + 1] = std::min(dp[i + 1], dp[i] + cost[i]);

            }

            if (i + 2 < dp.size()) {
                if(dp[i+2] == -1)
                    dp[i+2] = dp[i] + cost[i];
                else
                    dp[i + 2] = std::min(dp[i + 2], dp[i] + cost[i]);
            }
        }

        return dp[N];
    }
};

int main() {
    std::cout << Solution{}.minCostClimbingStairs({10, 15, 20}) << "\n";
    std::cout << Solution{}.minCostClimbingStairs({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}) << "\n";
}
