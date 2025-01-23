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
#include <string>
#include <vector>

bool can_construct(std::string target, const std::vector<std::string>& wordbank) {
    size_t N = target.size();
    std::vector<bool> dp(N + 1, false);

    dp[0] = true;

    for(size_t i = 0; i < dp.size(); ++i) {
        for(const auto& word : wordbank) {
            auto substr = target.substr(i, word.size());
            if(substr == word && dp[i] == true && i + word.size() < dp.size())
                dp[i+word.size()] = true;
        }
    }

    return dp[N];
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