#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        auto N = static_cast<size_t>(n);
        std::vector<int> dp(N + 1, 0);
        dp[0] = 1;

        for(size_t i = 0; i < dp.size(); ++i) {
            if(i + 1 < dp.size())
                dp[i+1] += dp[i];
            if(i + 2 < dp.size())
                dp[i+2] += dp[i];
        }

        return dp[N];
    }
};

int main() {
    std::cout << Solution{}.climbStairs(2) << "\n";
    std::cout << Solution{}.climbStairs(3) << "\n";
}