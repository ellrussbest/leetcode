#include <iostream>
#include <stack>
#include <unordered_map>

class Solution {
   public:
    bool isValid(const std::string& s) {
        std::stack<char> st;

        for (const auto& c : s) {
            if (is_closing_brackets(c)) {
                if (st.empty()) return false;

                auto it = m_pairs.find(c);
                if (it->second != st.top()) return false;
                st.pop();
            } else {
                st.emplace(c);
            }
        }

        return st.empty();
    }

   private:
    bool is_closing_brackets(const char& c) {
        return c == '}' || c == ')' || c == ']';
    }

   private:
    std::unordered_map<char, char> m_pairs{
        {'}', '{'},
        {')', '('},
        {']', '['},
    };
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.isValid("()") << "\n";
    std::cout << Solution{}.isValid("()[]{}") << "\n";
    std::cout << Solution{}.isValid("(]") << "\n";
    std::cout << Solution{}.isValid("([])") << "\n";
}