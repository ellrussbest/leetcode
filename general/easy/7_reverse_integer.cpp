#include <iostream>
#include <limits>

class Solution {
   public:
    int reverse(int x) {
        bool issigned = (x < 0);
        int res{};

        while (x) {
            int digit = x % 10;

            if ((!issigned &&
                 res > ((std::numeric_limits<int>::max() - digit) / 10)) ||
                (issigned &&
                 res < ((std::numeric_limits<int>::lowest() - digit) / 10)))
                return 0;

            res = res * 10 + digit;
            x /= 10;
        }

        return res;
    }
};

int main() {
    std::cout << Solution{}.reverse(123) << "\n";
    std::cout << Solution{}.reverse(-123) << "\n";
    std::cout << Solution{}.reverse(120) << "\n";
    std::cout << Solution{}.reverse(std::numeric_limits<int>::max()) << "\n";
    std::cout << Solution{}.reverse(std::numeric_limits<int>::lowest()) << "\n";
}