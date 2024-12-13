#include <iostream>
#include <stack>
#include <unordered_map>

class Solution {
   public:
    bool isValid(const std::string& s) {
        static std::unordered_map<char, char> pairs{
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        std::stack<char> st;

        for (const auto& c : s) {
            if (auto it = pairs.find(c); it != pairs.end()) {
                if (st.empty() || it->second != st.top()) return false;
                st.pop();
            } else {
                st.emplace(c);
            }
        }

        return st.empty();
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.isValid("()") << "\n";
    std::cout << Solution{}.isValid("()[]{}") << "\n";
    std::cout << Solution{}.isValid("(]") << "\n";
    std::cout << Solution{}.isValid("([])") << "\n";
}