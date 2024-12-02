#include <cctype>
#include <iostream>
#include <stack>
#include <string>

class Solution {
   public:
    std::string decodeString(const std::string& s) {
        std::stack<std::pair<int, std::string>> st;
        std::string curr_string{};
        int count = 0;

        for (const char& ch : s) {
            if (ch == '[') {
                st.emplace(count, curr_string);
                curr_string.clear();
                count = 0;
            } else if (ch == ']') {
                auto& [prev_count, prev_string] = st.top();

                std::string decoded{};
                for (int i = 0; i < prev_count; ++i) {
                    decoded += curr_string;
                }

                curr_string = std::move(prev_string) + decoded;
                st.pop();
            } else if (std::isdigit(ch)) {
                count = count * 10 + (ch - '0');
            } else {
                curr_string += ch;
            }
        }

        return curr_string;
    }
};

int main() {
    std::cout << Solution{}.decodeString("3[a]2[bc]") << "\n";  // "aaabcbc"
    std::cout << Solution{}.decodeString("3[a2[c]]") << "\n";   // "accaccacc"
    std::cout << Solution{}.decodeString("2[abc]3[cd]ef") << "\n";  // "abcabccdcdcdef"
}
