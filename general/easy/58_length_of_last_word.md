# lengthOfLastWord Solution: Intuition

This solution calculates the length of the last word in a given string `s`, where words are defined as sequences of non-space characters. The approach involves working with reverse iterators to identify the last word without needing to manipulate the entire string.

## Optimized Approach: Using Reverse Iterators

The solution uses reverse iterators to efficiently find the last word in the string. The algorithm first skips trailing spaces, then identifies the start of the last word, and finally measures its length by iterating backwards until the next space or the beginning of the string.

### Step-by-Step Explanation:

1. **Find the First Non-Space Character from the End**:
   - We start by using `std::find_if_not` with a reverse iterator to skip any trailing spaces in the string. This finds the first non-space character from the end of the string.

   ```cpp
   auto first = std::find_if_not(s.rbegin(), s.rend(), [](const auto& c) {
       return std::isspace(c);
   });
   ```

2. **Find the End of the Last Word**:
   - Once we have the first non-space character, we use `std::find_if` to find the next space (or the end of the string) starting from this position. This identifies the boundaries of the last word.

   ```cpp
   auto last = std::find_if(first, s.rend(), [](const auto& c) {
       return std::isspace(c);
   });
   ```

3. **Calculate the Length of the Last Word**:
   - The length of the last word is determined by calculating the distance between the two iterators: `first` (the start of the last word) and `last` (either the next space or the end of the string).

   ```cpp
   return static_cast<int>(std::distance(first, last));
   ```

4. **Return the Result**:
   - The function returns the length of the last word. If no non-space characters are found, the result is `0`.

5. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the string. The algorithm iterates through the string once using reverse iterators to find the start and end of the last word.
   - **Space Complexity**: The space complexity is **O(1)**, as the algorithm uses only a constant amount of additional space.

---

## Key Insights:

### Efficiency of the Approach:
- **Reverse Iterators**: By using reverse iterators, we avoid the need to modify or split the string, making the algorithm efficient and elegant.
- **Linear Scan**: The algorithm efficiently scans the string in linear time **O(n)** while ensuring that we handle cases with multiple spaces or trailing spaces.

---

## Example Walkthrough:

Consider the input `s = "Hello World"`:

### Step-by-Step Execution:

1. **Step 1**: The reverse iterator skips the trailing space after "World".
2. **Step 2**: The iterator points to the 'W' in "World".
3. **Step 3**: The next space is found, indicating the end of the last word.
4. **Step 4**: The distance between the two iterators gives the length of the last word, which is `5` (for "World").

For `s = "   fly me   to   the moon  "`:

1. The reverse iterator skips the spaces after "moon".
2. The iterator points to the 'm' in "moon".
3. The next space is found, and the length of the word "moon" is calculated as `4`.

---

## Final Thoughts:

- **Optimized Approach**: This approach is efficient, with a time complexity of **O(n)** and a constant space complexity of **O(1)**. The use of reverse iterators makes it both elegant and easy to understand.
  
- **Edge Cases**: The algorithm handles multiple spaces, leading or trailing spaces, and even cases where the string is empty or contains only spaces, returning `0` in such cases.

---

## Example Usage:

```cpp
std::cout << Solution{}.lengthOfLastWord("Hello World") << "\n";  // Output: 5
std::cout << Solution{}.lengthOfLastWord("   fly me   to   the moon  ") << "\n";  // Output: 4
std::cout << Solution{}.lengthOfLastWord("luffy is still joyboy") << "\n";  // Output: 7
```

---

This approach efficiently calculates the length of the last word in a string using reverse iterators, making it an optimal solution for the problem.

