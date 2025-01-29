#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        auto first = s.begin();
        auto last = s.begin();

        for(auto it = s.begin(); it != s.end(); ++it) {
            auto [odd_first, odd_last, odd_dist] = expand_around_center(s, it, false);
            auto [even_first, even_last, even_dist] = expand_around_center(s, it, true);

            if(odd_dist > std::distance(first, last))
                first = odd_first, last = odd_last;
            if(even_dist > std::distance(first, last))
                first = even_first, last = even_last;
        }

        return {first, last};
    }
private:
    template <typename BidirIt>
    std::tuple<BidirIt, BidirIt, typename std::iterator_traits<BidirIt>::difference_type> 
    expand_around_center(const std::string& s, BidirIt center, bool is_even) {
        auto left = --std::make_reverse_iterator(center);
        auto right = is_even ? std::next(center) : center;

        while(left != s.rend() && right != s.end()) {
            if(*left == *right)
                ++left, ++right;
            else
                break;
        }

        return {left.base(), right, std::distance(left.base(), right)};
    }
};

int main() {
    std::cout << Solution{}.longestPalindrome("babad") << "\n";
    std::cout << Solution{}.longestPalindrome("cbbd") << "\n";
    std::cout << Solution{}.longestPalindrome("ac") << "\n";
    std::cout << Solution{}.longestPalindrome("abb") << "\n";
}