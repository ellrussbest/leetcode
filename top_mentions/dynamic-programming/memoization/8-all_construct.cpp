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
#include <unordered_map>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> all_construct_helper(std::string target, const std::vector<std::string>& wordbank,
                                                           std::unordered_map<std::string, std::vector<std::vector<std::string>>>& memo) {
    if(target.size() == 0)
        return {{}};
    
    if(auto it = memo.find(target); it != memo.end())
        return it->second;

    std::vector<std::vector<std::string>> res;
    for(const auto& word : wordbank) {
        if(target.starts_with(word)) {
            auto substr = target.substr(word.size());
            auto temp = all_construct_helper(std::move(substr), wordbank, memo);

            for(auto& candidate : temp) {
                candidate.emplace(candidate.begin(), word);
                res.emplace_back(candidate);
            }
        }
    }

    memo.emplace(target, res);
    return res;
}

std::vector<std::vector<std::string>> all_construct(std::string target, 
                                                    const std::vector<std::string>& wordbank) {
    std::unordered_map<std::string, std::vector<std::vector<std::string>>> memo;
    return all_construct_helper(target, wordbank, memo);
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
    std::cout << all_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                               {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"})
              << "\n";
}