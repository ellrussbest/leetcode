#include <vector>
#include <iostream>

size_t fibonacci(int n) {
    size_t N = static_cast<size_t>(n);
    std::vector<size_t> dp(N + 1, 0);

    dp[1] = 1;

    for(auto i = dp.begin(); i != dp.end(); ++i) {
        // +1 step ahead
        if(std::next(i) != dp.end()) {
            *std::next(i) += *i;

            // +2 steps ahead
            if(std::next(i, 2) != dp.end())
                *std::next(i, 2) += *i;
        }
    }

    return dp[N];
}


int main() {
    std::cout << fibonacci(6) << "\n";
    std::cout << fibonacci(7) << "\n";
    std::cout << fibonacci(8) << "\n";
    std::cout << fibonacci(50) << "\n";
}