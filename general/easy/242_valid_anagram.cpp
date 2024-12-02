#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    bool isAnagram(std::string&& s, std::string&& t) {
        if (s.size() != t.size()) return false;

        std::vector<int> count(26, 0);  // for 'a' to 'z'

        for (char c : s) {
            ++count[static_cast<size_t>(c - 'a')];
        }

        for (char c : t) {
            if (--count[static_cast<size_t>(c - 'a')] < 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.isAnagram("anagram", "nagaram") << "\n";
    std::cout << Solution{}.isAnagram("rat", "car") << "\n";
}