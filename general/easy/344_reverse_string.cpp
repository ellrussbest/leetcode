#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    void reverseString(std::vector<char>& s) {
        auto first = s.begin();
        auto last = s.rbegin();

        while (first < last.base()) {
            std::iter_swap(first, last);
            ++first, ++last;
        }
    }
};

std::ostream& operator<<(std::ostream& out, const std::vector<char>& s) {
    out << "{";
    for (char sep[]{0, ' ', 0}; const auto& c : s)
        out << sep << "'" << c << "'", sep[0] = ',';
    out << "}";
    return out;
}

int main() {
    std::vector a{'h', 'e', 'l', 'l', 'o'};
    std::vector b{'H', 'a', 'n', 'n', 'a', 'h'};

    Solution{}.reverseString(a);
    Solution{}.reverseString(b);

    std::cout << a << "\n";
    std::cout << b << "\n";
}

// Time Complexity (0(n))
// Space Complexity (0(1))