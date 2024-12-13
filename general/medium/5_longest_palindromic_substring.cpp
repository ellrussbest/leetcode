#include <iostream>
#include <iterator>

class Solution {
   public:
    std::string longestPalindrome(const std::string& s) {
        auto first = s.end();
        auto last = s.end();

        for (auto it = s.begin(); it != s.end(); ++it) {
            auto [odd_len, odd_start, odd_end] = expand_around_center(it, s);
            auto [even_len, even_start, even_end] =
                expand_around_center(it, s, true);

            if (odd_len > std::distance(first, last)) {
                first = odd_start;
                last = odd_end;
            }

            if (even_len > std::distance(first, last)) {
                first = even_start;
                last = even_end;
            }
        }

        return {first, last};
    }

    std::string longestPalindrome_bruteforce(const std::string& s) {
        auto res = std::string{};

        for (auto i = s.begin(); i != s.end(); ++i) {
            auto substr = std::string{};
            for (auto j = i; j != s.end(); ++j) {
                substr += *j;
                if (is_palindrome(substr.begin(), substr.end()) &&
                    substr.size() > res.size())
                    res = substr;
            }
        }
        return res;
    }

   private:
    template <typename BidirIt>
    std::tuple<long int, BidirIt, BidirIt> 
    expand_around_center(BidirIt center, const std::string& s, bool is_even = false) {
        auto& right = center;
        auto left = --std::make_reverse_iterator(right);
        if (is_even) ++right;

        while (left != s.rend() && right != s.end()) {
            if (*left != *right) break;
            ++left, ++right;
        }

        return {std::distance(left.base(), right), left.base(), right};
    }

    template <typename BidirIt>
    bool is_palindrome(BidirIt first, BidirIt last) {
        while (first != last && first != --last)
            if (*first++ != *last) return false;
        return true;
    }
};

int main() {
    std::cout << Solution{}.longestPalindrome_bruteforce("babad") << "\n";
    std::cout << Solution{}.longestPalindrome_bruteforce("cbbd") << "\n";

    std::cout << Solution{}.longestPalindrome("babad") << "\n";
    std::cout << Solution{}.longestPalindrome("cbbd") << "\n";
}