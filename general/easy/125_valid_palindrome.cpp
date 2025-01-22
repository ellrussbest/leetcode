#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

class Solution {
   public:
    bool isPalindrome(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), [](auto& c) {
            return static_cast<char>(
                std::tolower(static_cast<unsigned char>(c)));
        });

        auto it = std::remove_if(s.begin(), s.end(), [](auto c) {
            return !std::isalnum(static_cast<unsigned char>(c));
        });
        s.erase(it, s.end());

        auto half = static_cast<int>(s.size() / 2);
        return std::equal(s.begin(), std::next(s.begin(), half), s.rbegin());
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.isPalindrome("A man, a plan, a canal: Panama") << "\n";
    std::cout << Solution{}.isPalindrome("race a car") << "\n";
    std::cout << Solution{}.isPalindrome(" ") << "\n";
}