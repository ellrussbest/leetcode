/**
 * Write a function `all_construct(target, wordbank)` that accepts target string
 * and an array of strings.
 *
 * The function should return 2d array containing all the ways that the `target`
 * can be constructed by concatenating elements of the `wordbank` array. Each
 * element of the 2d array should represent one combination that constructs the
 * `target`.
 *
 * You may reuse elements of `wordbank` as many times as needed.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>


std::vector<std::vector<std::string>> all_construct(std::string target, 
                                                    const std::vector<std::string>& wordbank) {
    size_t N = target.size();
    std::vector<std::vector<std::vector<std::string>>> dp{N+1, std::vector<std::vector<std::string>>{}};

    dp[0] = std::vector<std::vector<std::string>>{{}};

    for(size_t i = 0; i < dp.size(); ++i) {
        for(const auto& word : wordbank) {
            auto substr = target.substr(i, word.size());
            if(substr == word && !dp[i].empty() && i+word.size() < dp.size()) {
                auto cur = dp[i];
                auto& dest = dp[i+word.size()];
                
                std::for_each(cur.begin(), cur.end(), [&](auto& vec)mutable{
                    vec.emplace_back(word);
                    dest.emplace_back(std::move(vec));
                });
            }
        }
    }

    return dp[N];
}

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
    std::cout << all_construct("purple", {"purp", "p", "ur", "le", "purpl"})
              << "\n";
    std::cout << all_construct("abcdef",
                               {"ab", "abc", "cd", "def", "abcd", "ef", "c"})
              << "\n";
    std::cout << all_construct("skateboard",
                               {"bo", "rd", "ate", "t", "ska", "sk", "boar"})
              << "\n";
    std::cout << all_construct("enterapotentpot",
                               {"a", "p", "ent", "enter", "ot", "o", "t"})
              << "\n";
    // std::cout << all_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
    //                            {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"})
    //           << "\n";
}