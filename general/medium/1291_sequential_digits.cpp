#include <cmath>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector digits{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<int> res;

        int base = static_cast<int>(std::log10(low));
        int divisor = static_cast<int>(std::pow(10, base));

        auto first = --std::next(digits.begin(), static_cast<int>(low / divisor));
        auto last = digits.end();
        auto curr = 0;

        if(std::distance(digits.begin(), first) + base < 9) {
            last = ++std::next(first, base);
            curr = construct_number(first, last);
        }

        while (curr <= high) {
            if(curr >= low) 
                res.emplace_back(curr);
            if (base >= 8)
                break;


            if (last == digits.end()) {
                ++base;
                divisor = static_cast<int>(std::pow(10, base));
                first = digits.begin();
                last = ++std::next(first, base);
                curr = construct_number(first, last);
            }else {
                int msv = static_cast<int>(curr / divisor) * divisor;
                curr -= msv;
                curr = curr * 10 + *last++;
            }
        }

        return res;
    }

   private:
    template <typename ForwardIt>
    int construct_number(ForwardIt first, ForwardIt last) {
        int res = 0;
        while (first != last) 
            res = res * 10 + *first++;
        return res;
    }
};

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
    out << "{";
    for (char sep[]{0, ' ', 0}; const auto& el : v)
        out << sep << el, sep[0] = ',';
    out << "}";

    return out;
}

int main() {
    std::cout << Solution{}.sequentialDigits(30, 100) << "\n";
    std::cout << Solution{}.sequentialDigits(100, 300) << "\n";
    std::cout << Solution{}.sequentialDigits(1000, 13000) << "\n";
    std::cout << Solution{}.sequentialDigits(58, 155) << "\n";
    std::cout << Solution{}.sequentialDigits(100000000, 1000000000) << "\n";
    std::cout << Solution{}.sequentialDigits(744, 1928) << "\n";
    std::cout << Solution{}.sequentialDigits(8511, 23553) << "\n";
    std::cout << Solution{}.sequentialDigits(31365477, 514800930) << "\n";
}