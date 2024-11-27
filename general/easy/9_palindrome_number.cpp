#include <iostream>

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        auto temp = x;
        long comp{};

        while (temp) {
            int digit = temp % 10;
            comp = comp * 10 + digit;
            temp /= 10;
        }

        return comp == x;
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.isPalindrome(121) << "\n";
    std::cout << Solution{}.isPalindrome(-121) << "\n";
    std::cout << Solution{}.isPalindrome(10) << "\n";
}