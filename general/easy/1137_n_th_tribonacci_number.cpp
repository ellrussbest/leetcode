#include <iostream>
#include <vector>

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
            
        auto N = static_cast<size_t>(n);
        std::vector<int> dp(N+1, 0);
        dp[1] = 1;

        for(size_t i = 0; i < dp.size(); ++i) {
            for(size_t j = 1; j <= 3; ++j) {
                if(i + j < dp.size())
                    dp[i+j] += dp[i];
            }
        }

        return dp[N];
    }
};

int main() {
    std::cout << Solution{}.tribonacci(4) << "\n";
    std::cout << Solution{}.tribonacci(25) << "\n";
}