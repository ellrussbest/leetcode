#include <iostream>

class Solution {
   public:
    int trailingZeroes(int n) {
        int fives{};
        for (int i = 5; i <= n; i = i * 5) fives += (n / i);

        return fives;
    }

    int trailingZeroes_bruteforce(int n) {
        unsigned long fact = 1;
        for (auto i = 2; i <= n; ++i) fact *= static_cast<unsigned long>(i);

        int count = 0;
        while (fact % 10 == 0) {
            ++count;
            fact /= 10;
        }

        return count;
    }
};

int main() {
    std::cout << Solution{}.trailingZeroes_bruteforce(3) << "\n";
    std::cout << Solution{}.trailingZeroes_bruteforce(5) << "\n";
    std::cout << Solution{}.trailingZeroes_bruteforce(0) << "\n";


    std::cout << Solution{}.trailingZeroes(3) << "\n";
    std::cout << Solution{}.trailingZeroes(5) << "\n";
    std::cout << Solution{}.trailingZeroes(0) << "\n";
}