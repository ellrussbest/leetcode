#include <algorithm>
#include <iostream>
#include <unordered_set>

class Solution {
   public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::unordered_set<char> set;
        size_t max_len = 0;

        for(size_t i = 0, j = 0; j < s.size(); ++j) {
            auto it = set.find(s[j]);
            
            while(it != set.end()) {
                set.erase(it);
                it = set.find(s[i++]);
            }

            set.emplace(s[j]);
            max_len = std::max(max_len, j - i + 1);
        }

        return static_cast<int>(max_len);
    }

    int lengthOfLongestSubstring_bruteforce(const std::string& s) {
        size_t max_len = 0;
        for(auto i = s.begin(); i != s.end(); ++i) {
            auto substr = std::string{};
            for(auto j = i; j != s.end(); ++j) {
                if(substr.contains(*j)) break;
                substr += *j;
                max_len = std::max(max_len, substr.size());
            }
        }
        return static_cast<int>(max_len);
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