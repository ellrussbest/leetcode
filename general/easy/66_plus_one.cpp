#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> plusOne(std::vector<int>&& digits) {
        int carry = 1;

        for(auto it = digits.rbegin(); it != digits.rend(); ++it) {
            auto prev  = *it;
            *it = (prev + carry) % 10;
            carry = (prev + carry) / 10;

            if(carry == 0)
                break;
        }

        if(carry == 1)
            digits.insert(digits.begin(), carry);
        
        return digits;
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
    std::cout << Solution{}.plusOne({1, 2, 3}) << "\n";
    std::cout << Solution{}.plusOne({4, 3, 2, 1}) << "\n";
    std::cout << Solution{}.plusOne({9}) << "\n";
}