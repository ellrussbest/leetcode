#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> res(static_cast<size_t>(n));

        int count = 1;
        while (count <= n) {
            std::string el{};

            if (count % 3 == 0) el += "Fizz";
            if (count % 5 == 0) el += "Buzz";
            if (el.size() == 0) el += std::to_string(count);

            *(res.begin() + count - 1) = std::move(el);
            ++count;
        }

        return res;
    }
};

// overload string insertion operator
std::ostream& operator<<(std::ostream& out, const std::vector<std::string>& v) {
    out << "{";
    for (char sep[]{0, ' ', 0}; const auto& el : v)
        out << sep << el, sep[0] = ',';
    out << "}";

    return out;
}

int main() {
    std::cout << Solution{}.fizzBuzz(3) << "\n";
    std::cout << Solution{}.fizzBuzz(5) << "\n";
    std::cout << Solution{}.fizzBuzz(15) << "\n";
}

// Time Complexity: O(n)
// Space Complexity: O(n)