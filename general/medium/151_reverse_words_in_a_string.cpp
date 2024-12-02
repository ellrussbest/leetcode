#include <algorithm>
#include <cctype>
#include <iostream>

class Solution {
public:
    std::string reverseWords(std::string&& s) {
        trim(s);

        std::reverse(s.begin(), s.end());

        auto start = s.begin();
        while (start != s.end()) {
            start = std::find_if_not(start, s.end(), [](const unsigned char& c) { return std::isspace(c); });

            auto end = std::find_if(start, s.end(), [](const unsigned char& c) { return std::isspace(c); });

            std::reverse(start, end);
            start = end;
        }

        // Remove extra spaces between words
        removeExtraSpaces(s);

        return s;
    }

private:
    void trim(std::string& s) {
        ltrim(s);
        rtrim(s);
    }

    void ltrim(std::string& s) {
        auto it = std::find_if_not(s.begin(), s.end(), [](const unsigned char& c) { return std::isspace(c); });
        s.erase(s.begin(), it);
    }

    void rtrim(std::string& s) {
        auto it = std::find_if_not(s.rbegin(), s.rend(), [](const unsigned char& c) { return std::isspace(c); });
        s.erase(it.base(), s.end());
    }

    void removeExtraSpaces(std::string& s) {
        auto it = std::unique(s.begin(), s.end(), [](char lhs, char rhs) {
            return std::isspace(lhs) && std::isspace(rhs);
        });
        
        s.erase(it, s.end());
    }
};

int main() {
    std::cout << Solution{}.reverseWords("the sky is blue") << "\n";         // Output: "blue is sky the"
    std::cout << Solution{}.reverseWords("  hello world  ") << "\n";         // Output: "world hello"
    std::cout << Solution{}.reverseWords("a good   example") << "\n";       // Output: "example good a"
}