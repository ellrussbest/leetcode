/**
 * Write a function `count_construct(target, wordbank)` that accepts a target
 * string and an array of strings.
 *
 * The function should return the number of ways that the `target` can be
 * constructed by concatenating elemtns of the `wordbank` array.
 *
 * You may reuse elements of `wordbank` as many times as needed.
 */
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

size_t count_construct_helper(std::string target, const std::vector<std::string>& wordbank,
                              std::unordered_map<std::string, size_t>& memo) {
    if (target.size() == 0) 
        return 1;

    if (auto it = memo.find(target); it != memo.end()) 
        return it->second;

    size_t count = 0;
    for (const auto& word : wordbank) {
        if (target.starts_with(word)) {
            auto substr = target.substr(word.size());
            auto res = count_construct_helper(std::move(substr), wordbank, memo);
            count += res;
        }
    }

    memo.emplace(target, count);
    return count;
}

size_t count_construct(std::string target,
                       const std::vector<std::string>& wordbank) {
    std::unordered_map<std::string, size_t> memo;
    return count_construct_helper(target, wordbank, memo);
}

int main() {
    std::cout << count_construct("purple", {"purp", "p", "ur", "le", "purpl"})
              << "\n";
    std::cout << count_construct("abcdef", {"ab", "abc", "cd", "def", "abcd"})
              << "\n";
    std::cout << count_construct("skateboard",
                                 {"bo", "rd", "ate", "t", "ska", "sk", "boar"})
              << "\n";
    std::cout << count_construct("enterapotentpot",
                                 {"a", "p", "ent", "enter", "ot", "o", "t"})
              << "\n";
    std::cout << count_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                                 {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"})
              << "\n";
}