#include <iostream>
#include <algorithm>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        auto first1 = t.begin();
        auto last1 = t.end();

        auto first2 = s.begin();
        auto last2 = s.end();

        while(true) {
            if(first2 == last2)
                return true;
            if(first1 == last1)
                return false;
            
            if(*first1 == *first2)
                ++first2;
            ++first1;
        }
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.isSubsequence("abc", "ahbgdc") << "\n";
    std::cout << Solution{}.isSubsequence("axc", "ahbgdc") << "\n";
}