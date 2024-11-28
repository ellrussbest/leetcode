#include <iostream>
#include <vector>

class Solution {
   public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        std::string res = strs[0];

        for(const auto& s : strs) {
            while(!s.starts_with(res)) {
                res.pop_back();
                if(res.empty()) return res;
            }
        }

        return res;
    }
};

int main() {
    std::cout << Solution{}.longestCommonPrefix({"flower", "flow", "flight"})
              << "\n";
    std::cout << Solution{}.longestCommonPrefix({"dog", "racecar", "car"})
              << "\n";
    std::cout << Solution{}.longestCommonPrefix({"abcd", "accd", "adcd"})
              << "\n";
}

// Time Complexity O(m*n)
// Space Complexity O(n)