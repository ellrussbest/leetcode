# longestPalindrome Solution: Intuition

This solution solves the problem of finding the longest palindromic substring in a given string `s`. It utilizes the **expand around center** technique, similar to the previous version, but the code has been refactored for better readability and efficiency. The algorithm checks for palindromes by considering each character (and pair of characters) as a potential center, expanding outward to identify both odd and even-length palindromes.

## Step-by-Step Explanation:

1. **Initialization**:
   We initialize two iterators:
   - `first`: points to the beginning of the longest palindromic substring found.
   - `last`: points to the end of the longest palindromic substring found.

   ```cpp
   auto first = s.begin();
   auto last = s.begin();
   ```

2. **Iterate Over Each Character**:
   The algorithm iterates through each character of the string, treating it as the center of a potential palindrome. For each character, it checks for palindromes of both odd and even lengths using the `expand_around_center` function.

   ```cpp
   for(auto it = s.begin(); it != s.end(); ++it) {
       auto [odd_first, odd_last, odd_dist] = expand_around_center(s, it, false);
       auto [even_first, even_last, even_dist] = expand_around_center(s, it, true);
   }
   ```

3. **Update the Longest Palindrome**:
   For each expansion (odd and even), if the length of the found palindrome is greater than the current longest palindrome, we update `first` and `last` to the starting and ending iterators of that palindrome.

   ```cpp
   if(odd_dist > std::distance(first, last))
       first = odd_first, last = odd_last;
   if(even_dist > std::distance(first, last))
       first = even_first, last = even_last;
   ```

4. **Return the Result**:
   After checking all possible centers, the substring between `first` and `last` represents the longest palindromic substring. We return it.

   ```cpp
   return {first, last};
   ```

## Helper Functions:

### expand_around_center

The `expand_around_center` function is a key part of the solution. It takes a center and expands outwards in both directions (left and right) to check if the substring is a palindrome. It works for both odd and even-length palindromes.

#### Parameters:
- `s`: The string in which we are searching for palindromes.
- `center`: The center of the potential palindrome (an iterator pointing to the current character).
- `is_even`: A boolean indicating whether we are looking for an even-length palindrome. The default is `false` (odd-length palindrome).

#### Logic:
1. We initialize two iterators, `left` and `right`, around the center.
2. If `is_even` is true, we adjust the `right` pointer to the next character to handle even-length palindromes.
3. We then expand the pointers outward while ensuring the characters at `left` and `right` are equal.
4. The function continues to expand until the characters differ or the pointers go out of bounds.

```cpp
template <typename BidirIt>
std::tuple<BidirIt, BidirIt, typename std::iterator_traits<BidirIt>::difference_type> 
expand_around_center(const std::string& s, BidirIt center, bool is_even) {
    auto left = --std::make_reverse_iterator(center);
    auto right = is_even ? std::next(center) : center;

    while(left != s.rend() && right != s.end()) {
        if(*left == *right)
            ++left, ++right;
        else
            break;
    }

    return {left.base(), right, std::distance(left.base(), right)};
}
```

#### Return:
- **Start and end iterators**: `left.base()` and `right` give the iterators for the start and end of the palindrome.
- **Length of palindrome**: `std::distance(left.base(), right)` gives the length of the palindrome.

---

## Key Insights:

- **Expand Around Center**:
  - The approach exploits the fact that a palindrome mirrors around its center. By expanding outwards from each center, we can efficiently find palindromes of both odd and even lengths.
  
- **Time Complexity**:
  - **Time Complexity**: The time complexity is **O(n²)**, where `n` is the length of the string. For each character, we expand around it to check for palindromes, and expanding takes linear time.
  - **Space Complexity**: The space complexity is **O(1)**, as no additional space is required beyond a few variables.

---

## Final Thoughts:

The **expand around center** approach is efficient for finding palindromes. The updated code is more compact, and the algorithm retains a quadratic time complexity, but is structured to better reflect the goal of finding the longest palindrome in a more clean and readable manner.

--- 

## Example Walkthrough:

Consider the input string `s = "babad"`:

1. **Process**:
   - Start with the center at `"b"`, expand to find `"bab"`, then `"aba"`, and so on.
   - The longest palindrome found is `"bab"`, which has a length of `3`.

2. **Other Examples**:
   - `s = "cbbd"`: The longest palindrome is `"bb"`, with a length of `2`.
   - `s = "ac"`: The longest palindrome is `"a"`, with a length of `1`.
   - `s = "abb"`: The longest palindrome is `"bb"`, with a length of `2`.

---

## Final Comparison:

- **Efficiency**: The **expand-around-center** solution is efficient (`O(n²)` time complexity) compared to brute-force solutions.
- **Memory Usage**: Both methods use **O(1)** space, and this solution avoids unnecessary substring storage like in the brute-force approach.
