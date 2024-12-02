#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
        if (strs.empty()) return {{""}};

        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, std::vector<std::string>> m_map;

        for (size_t i = 0; i < strs.size(); ++i) {
            auto key = strs[i];
            std::sort(key.begin(), key.end());
            auto [it, success] =
                m_map.try_emplace(key, std::vector<std::string>{strs[i]});
            if (!success) it->second.emplace_back(strs[i]);
        }

        for (auto& [key, val] : m_map) res.emplace_back(std::move(val));

        return res;
    }
};

std::ostream& operator<<(std::ostream& out,
                         std::vector<std::vector<std::string>> vv) {
    out << "{";
    for (char sep_1[]{0, ' ', 0}; const auto& v : vv) {
        out << sep_1 << "\n\t{";
        for (char sep_2[]{0, ' ', 0}; const auto& el : v)
            out << sep_2 << el, sep_2[0] = ',';
        out << "}";
        sep_1[0] = ',';
    }
    out << "\n}";

    return out;
}

int main() {
    std::cout << Solution{}.groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"}) << "\n";
    std::cout << Solution{}.groupAnagrams({""}) << "\n";
    std::cout << Solution{}.groupAnagrams({"a"}) << "\n";
}