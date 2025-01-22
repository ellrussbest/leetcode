#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        size_t N = static_cast<size_t>(n);
        std::vector<std::string> res(N);

        for(size_t i = 0; i < N; ++i) {
            std::string s{};

            if((i + 1) % 3 == 0)
                s += "Fizz";
            if((i + 1) % 5 == 0)
                s += "Buzz";
            if(s.size() == 0)
                s += std::to_string((i + 1));
            res[i] = std::move(s);
        }

        return res;
    }
};

// overload stream insertion operator
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
