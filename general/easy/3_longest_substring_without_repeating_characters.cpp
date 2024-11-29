#include <algorithm>
#include <iostream>
#include <unordered_set>

class Solution {
   public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::unordered_set<char> char_set;
        int max = 0;

        for (size_t i = 0, j = 0; j < s.size(); ++j) {
            auto it = char_set.find(s[j]);

            while (it != char_set.end()) {
                char_set.erase(it);
                it = char_set.find(s[i]);
                ++i;
            }

            char_set.insert(s[j]);
            max = std::max(max, static_cast<int>(j - i + 1));
        }

        return max;
    }

    int lengthOfLongestSubstring_bruteforce(const std::string& s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;

        int max{};

        for (size_t i = 0; i < s.size(); ++i) {
            std::string substr{};

            for (size_t j = i; j < s.size(); ++j) {
                if (!substr.contains(s[j])) {
                    substr += s[j];
                    max = std::max(max, static_cast<int>(substr.size()));
                } else
                    break;
            }
        }

        return max;
    }
};

int main() {
    std::cout << Solution{}.lengthOfLongestSubstring_bruteforce("abcabcbb")
              << "\n";
    std::cout << Solution{}.lengthOfLongestSubstring_bruteforce("bbbbb")
              << "\n";
    std::cout << Solution{}.lengthOfLongestSubstring_bruteforce("pwwkew")
              << "\n";
    std::cout << Solution{}.lengthOfLongestSubstring_bruteforce("au") << "\n";

    std::cout << Solution{}.lengthOfLongestSubstring("abcabcbb") << "\n";
    std::cout << Solution{}.lengthOfLongestSubstring("bbbbb") << "\n";
    std::cout << Solution{}.lengthOfLongestSubstring("pwwkew") << "\n";
    std::cout << Solution{}.lengthOfLongestSubstring("au") << "\n";
}