# lengthOfLongestSubstring Solution: Intuition

This solution solves the problem of finding the length of the longest substring without repeating characters in a given string `s`. The solution uses the **sliding window** technique with the help of an `unordered_set` to efficiently track the characters in the current window. The algorithm expands the window to the right and shrinks it from the left when a duplicate character is found, ensuring that only unique characters remain in the window.

## Step-by-Step Explanation:

1. **Initialization**:
   We initialize two variables:
   - `set`: an unordered set that stores the characters of the current substring without duplicates.
   - `max_len`: a size_t integer to keep track of the length of the longest substring found so far.

   ```cpp
   std::unordered_set<char> set;
   size_t max_len = 0;
   ```

2. **Sliding Window with Two Pointers**:
   The algorithm uses two pointers (`i` and `j`) to represent the boundaries of the sliding window:
   - `i`: the start of the window.
   - `j`: the end of the window (we iterate over it as we go through the string).

   The sliding window expands by moving `j` to the right. If a duplicate character is found (i.e., the character is already in `set`), we shrink the window by moving `i` to the right, removing characters from the set until the duplicate is removed.

   ```cpp
   for(size_t i = 0, j = 0; j < s.size(); ++j) {
       auto it = set.find(s[j]);
   ```

3. **Handling Duplicate Characters**:
   If a character at `s[j]` is found in `set` (i.e., it is a duplicate), we remove characters starting from `s[i]` from the set and increment `i` until `s[j]` can be added to the set without duplication.

   ```cpp
   while(it != set.end()) {
       set.erase(it);
       it = set.find(s[i++]);
   }
   ```

4. **Expanding the Window**:
   After ensuring the substring between `i` and `j` contains no duplicates, we add `s[j]` to `set` and update `max_len` if the length of the current substring (`j - i + 1`) is greater than the current `max_len`.

   ```cpp
   set.emplace(s[j]);
   max_len = std::max(max_len, j - i + 1);
   ```

5. **Return the Result**:
   After iterating through the entire string, `max_len` will hold the length of the longest substring without repeating characters.

   ```cpp
   return static_cast<int>(max_len);
   ```

## Key Insights:

- **Sliding Window**:
  - The sliding window approach allows us to efficiently track substrings by expanding and contracting the window dynamically.

- **Efficient Character Tracking**:
  - The use of `unordered_set` allows for **constant-time** checks and updates, ensuring efficient tracking of characters within the current window.

- **Time Complexity**:
  - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the input string `s`. We only iterate through the string once, with each character being added and removed from the set at most once.
  - **Space Complexity**: The space complexity is **O(k)**, where `k` is the size of the character set (i.e., the number of unique characters in the string). In the worst case, all characters in the string could be unique.

---

## Final Thoughts:

The sliding window approach provides an efficient way to find the longest substring without repeating characters. By dynamically adjusting the window size and using an unordered set for fast lookups, we achieve **O(n)** time complexity and **O(k)** space complexity, making this approach both time and space efficient.

---

# lengthOfLongestSubstring_bruteforce Solution: Intuition

This brute-force solution solves the same problem of finding the length of the longest substring without repeating characters in a given string `s`. However, instead of using a sliding window, it checks all possible substrings, which leads to a more straightforward, but less efficient, approach.

## Step-by-Step Explanation:

1. **Iterate Over All Substrings**:
   We use two nested loops to generate all possible substrings of `s`:
   - The outer loop (`i`) defines the starting index of the substring.
   - The inner loop (`j`) defines the ending index of the substring.

   For each pair of indices `(i, j)`, we extract the substring and check if it contains any duplicate characters.

   ```cpp
   for(auto i = s.begin(); i != s.end(); ++i) {
       auto substr = std::string{};
       for(auto j = i; j != s.end(); ++j) {
   ```

2. **Check for Duplicates**:
   We check if the current substring (`substr`) contains any duplicates by using the `contains` function. If the character `*j` is already in the substring, we break the loop, as we don't need to check further characters for this particular substring.

   ```cpp
   if(substr.contains(*j)) break;
   substr += *j;
   max_len = std::max(max_len, substr.size());
   ```

3. **Update Maximum Length**:
   If the character is not a duplicate, we add it to the substring and update `max_len` to store the length of the longest valid substring found so far.

   ```cpp
   max_len = std::max(max_len, substr.size());
   ```

4. **Return the Result**:
   After checking all possible substrings, `max_len` will contain the length of the longest substring without repeating characters.

   ```cpp
   return static_cast<int>(max_len);
   ```

## Key Insights:

- **Brute-Force Approach**:
  - The brute-force method generates all possible substrings and checks for duplicates. This approach is simple but inefficient compared to the sliding window method.

- **Time Complexity**:
  - **Time Complexity**: The time complexity is **O(n^3)** in the worst case because we generate all substrings, and for each substring, we check if it contains duplicates (which takes linear time). The nested loops result in a cubic time complexity.
  - **Space Complexity**: The space complexity is **O(n)**, where `n` is the length of the string, as we are storing substrings and the characters within them.

---

## Final Thoughts:

The brute-force approach works for small input sizes but is inefficient for larger strings. It generates all possible substrings, which makes it **O(n^3)** in time complexity. For larger inputs, the sliding window approach is preferred due to its linear time complexity.

---

## Example Walkthrough:

Consider the input string `s = "abcabcbb"`:

1. **Brute-Force Approach**:
   - Start with the substring `"a"`, `"ab"`, `"abc"`, and so on.
   - When a duplicate is found (e.g., `"abcabc"`), we break out of the inner loop.
   - The longest substring without repeating characters is `"abc"`, which has a length of `3`.

2. **Sliding Window Approach**:
   - Start with an empty set and two pointers `i = 0`, `j = 0`.
   - Expand `j` to the right, adding characters to the set. If a duplicate is found, move `i` right to remove characters from the set.
   - The longest substring without repeating characters is `"abc"`, which has a length of `3`.

---

## Final Comparison:

- **Efficiency**: The sliding window solution is significantly more efficient (`O(n)` time) compared to the brute-force solution (`O(n^3)`).
- **Memory Usage**: Both solutions use **O(n)** space, but the sliding window method uses space more efficiently as it only tracks the characters in the current window.