#include <iostream>

class Solution {
public:
    int balancedStringSplit(std::string s) {
        int r = 0;
        int l = 0;
        int res = 0;

        for(const auto& c: s) {
            if(r > 0 && l > 0 && r == l) {
                ++res;
                r = 0;
                l = 0;
            }

            if(c == 'L')
                ++l;
            else
                ++r;
            
        }

        if(r == l)
            ++res;

        return res;
    }
};

int main() {
    std::cout << Solution{}.balancedStringSplit("RLRRLLRLRL") << "\n";
    std::cout << Solution{}.balancedStringSplit("RLRRRLLRLL") << "\n";
    std::cout << Solution{}.balancedStringSplit("LLLLRRRR") << "\n";
}