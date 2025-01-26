#include <iostream>
#include <vector>

class Solution {
public:
    int numSquares(int n) {
        size_t N = static_cast<size_t>(n);
        std::vector<int> dp(N+1, -1);
        dp[0] = 0;

        for(size_t i = 0; i < dp.size(); ++i) {
            size_t j = 1;
            auto sq = j * j;

            if(dp[i] != -1)
                while(sq <= N) {
                    if(i+sq < dp.size()) {
                        if(dp[i+sq] == -1)
                            dp[i+sq] = dp[i] + 1;
                        else
                            dp[i+sq] = std::min(dp[i+sq], dp[i] + 1);
                    }
                    ++j;
                    sq = j * j;
                }
        }

        return dp[N];
    }
};

int main() {
    std::cout << Solution{}.numSquares(12) << "\n";
    std::cout << Solution{}.numSquares(13) << "\n";
}