#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<std::string> findRepeatedDnaSequences(const std::string& s) {
        std::unordered_map<std::string, int> map;
        std::vector<std::string> res;

        if (s.size() >= 10)
            for (size_t i = 0; i <= s.size() - 10; ++i) {
                auto substr = s.substr(i, 10);

                auto [it, success] = map.try_emplace(std::move(substr), 1);
                if (!success) ++it->second;

                if (it->second == 2) res.emplace_back(it->first);
            }

        return res;
    }
};

std::ostream& operator<<(std::ostream& out, const std::vector<std::string>& v) {
    out << "{";
    for (char sep[]{0, ' ', 0}; const auto& s : v)
        out << sep << s, sep[0] = ',';
    out << "}";

    return out;
}

int main() {
    std::cout << Solution{}.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT") << "\n";
    std::cout << Solution{}.findRepeatedDnaSequences("AAAAAAAAAAAAA") << "\n";
    std::cout << Solution{}.findRepeatedDnaSequences("AAAAAAAAAAA") << "\n";
}