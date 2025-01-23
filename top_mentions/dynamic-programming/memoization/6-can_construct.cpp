/**
 *
 * Write a function `can_construct(target, wordbank)` that accepts a
 * target string and an array of strings.
 *
 * The function should return a boolean indicating whether or not the `target`
 * can be constructed by concatenating elements of the `wordbank` array.
 *
 * You may reuse elements of `wordbank` as many times as needed.
 *
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

bool can_construct_helper(std::string target, const std::vector<std::string>& wordbank,
                          std::unordered_map<std::string, bool>& memo) {
    if (target.size() == 0)
        return true;

    if (auto it = memo.find(target); it != memo.end())
        return it->second;

    for (const auto& word : wordbank) {
        if (target.starts_with(word)) {
            auto substr = target.substr(word.size());
            auto res = can_construct_helper(std::move(substr), wordbank, memo);
            if (res)
                return true;
        }
    }

    memo.emplace(target, false);
    return false;
}

bool can_construct(std::string target, const std::vector<std::string>& wordbank) {
    std::unordered_map<std::string, bool> memo;
    return can_construct_helper(target, wordbank, memo);
}

int main() {
    std::cout << std::boolalpha
              << can_construct("abcdef", {"ab", "abc", "cd", "def", "abcd"})
              << "\n";
    std::cout << std::boolalpha
              << can_construct("skateboard",
                              {"bo", "rd", "ate", "t", "ska", "sk", "boar"})
              << "\n";
    std::cout << std::boolalpha
              << can_construct("enterapotentpot",
                              {"a", "p", "ent", "enter", "ot", "o", "t"})
              << "\n";
    std::cout << std::boolalpha
              << can_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                              {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"})
              << "\n";
}