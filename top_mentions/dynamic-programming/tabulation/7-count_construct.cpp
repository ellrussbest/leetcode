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
#include <string>
#include <vector>

size_t count_construct(std::string target,
                       const std::vector<std::string>& wordbank) {
    size_t N = target.size();
    std::vector<size_t> dp(N+1, 0);

    dp[0] = 1;

    for(size_t i = 0; i < dp.size(); ++i) {
        for(const auto& word : wordbank) {
            auto substr = target.substr(i, word.size());
            if(substr == word && dp[i] > 0 && i + word.size() < dp.size())
                dp[i+word.size()] += dp[i];
        }
    }

    return dp[N];
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