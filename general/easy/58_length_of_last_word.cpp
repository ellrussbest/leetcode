#include <algorithm>
#include <cctype>
#include <iostream>

class Solution {
   public:
    int lengthOfLastWord(std::string s) {
        auto first = std::find_if_not(s.rbegin(), s.rend(), [](const auto& c) {
            return std::isspace(c);
        });

        auto last = std::find_if(first, s.rend(),
                                 [](const auto& c) { return std::isspace(c); });

        return static_cast<int>(std::distance(first, last));
    }
};

int main() {
    std::cout << Solution{}.lengthOfLastWord("Hello World") << "\n";
    std::cout << Solution{}.lengthOfLastWord("   fly me   to   the moon  ")
              << "\n";
    std::cout << Solution{}.lengthOfLastWord("luffy is still joyboy") << "\n";
}