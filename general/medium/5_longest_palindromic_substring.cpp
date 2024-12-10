#include <iostream>

class Solution {
   public:
    std::string longestPalindrome(const std::string& s) {
        auto right = s.end();
        auto left = s.end();
        long int max_len = 0;

        for (auto i = s.begin(); i != s.end(); ++i) {
            auto [odd_len, odd_left, odd_right] = expand_around_center(i, s);
            auto [even_len, even_left, even_right] =
                expand_around_center(i, s, true);

            if (odd_len > max_len) {
                max_len = odd_len;
                left = odd_left;
                right = odd_right;
            }

            if (even_len > max_len) {
                max_len = even_len;
                left = even_left;
                right = even_right;
            }
        }

        return {left, right};
    }

    std::string longestPalindrome_bruteforce(const std::string& s) {
        if (s.size() == 1) return s;

        auto is_palindrome = [](const auto& substr) {
            auto left = substr.begin();
            auto right = substr.rbegin();

            while (left < right.base()) {
                if (*left != *right) return false;
                ++left, ++right;
            }

            return true;
        };

        std::string res{};

        for (size_t i = 0; i < s.size(); ++i) {
            std::string substr{};
            for (size_t j = i; j < s.size(); ++j) {
                substr += s[j];
                if (is_palindrome(substr) && substr.size() > res.size()) {
                    res = substr;
                }
            }
        }

        return res;
    }

   private:
    template <typename BidirIt>
    std::tuple<long int, BidirIt, BidirIt> expand_around_center(
        BidirIt right, const std::string& s, bool is_even = false) {
        auto left = --std::make_reverse_iterator(right);
        if (is_even) ++right;

        while (left != s.rend() && right != s.end() && *left == *right) {
            ++left, ++right;
        }

        return {std::distance(left.base(), right), left.base(), right};
    }
};

int main() {
    std::cout << Solution{}.longestPalindrome("babad") << "\n";
    std::cout << Solution{}.longestPalindrome("cbbd") << "\n";
    std::cout << Solution{}.longestPalindrome_bruteforce("babad") << "\n";
    std::cout << Solution{}.longestPalindrome_bruteforce("cbbd") << "\n";
}