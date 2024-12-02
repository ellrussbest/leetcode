#include <iostream>
#include <stack>

class Solution {
   public:
    int longestValidParentheses(const std::string& s) {
        std::stack<int> st;
        st.emplace(-1);
        int max_len = 0;

        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.emplace(static_cast<int>(i));
            } else {
                st.pop();
                if (st.empty()) {
                    st.emplace(static_cast<int>(i));
                } else {
                    max_len = std::max(max_len, static_cast<int>(i) - st.top());
                }
            }
        }

        return max_len;
    }
};

int main() {
    std::cout << Solution{}.longestValidParentheses("()(()()(()(") << "\n";
    std::cout << Solution{}.longestValidParentheses("(()") << "\n";
    std::cout << Solution{}.longestValidParentheses(")()())") << "\n";
    std::cout << Solution{}.longestValidParentheses("") << "\n";
    std::cout << Solution{}.longestValidParentheses("()()(()()()") << "\n";
    std::cout << Solution{}.longestValidParentheses("())(((())))") << "\n";
    std::cout << Solution{}.longestValidParentheses("()") << "\n";
    std::cout << Solution{}.longestValidParentheses("())") << "\n";
}