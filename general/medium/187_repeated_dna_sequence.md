# findRepeatedDnaSequences Solution: Intuition

This solution finds all DNA sequences (substrings of length 10) that are repeated within a given string `s`. The algorithm uses a sliding window of size 10 and an unordered map (`unordered_map`) to track the occurrences of each 10-character substring. If a substring is seen more than once, it is added to the result list. The solution ensures that we only add each repeated substring once, even if it appears multiple times.

## Step-by-Step Explanation:

1. **Initialization**:
   We initialize an empty hash map `map` to store each 10-character substring and its frequency of occurrence. We also initialize a result vector `res` to store the repeated substrings.

   ```cpp
   std::unordered_map<std::string, int> map;
   std::vector<std::string> res;
   ```

2. **Check for Minimum Length**:
   The algorithm checks if the string `s` is long enough to contain any 10-character substrings. If `s.size()` is less than 10, no valid 10-character substrings can exist, so the loop is skipped and an empty result is returned.

   ```cpp
   if (s.size() >= 10)
   ```

3. **Sliding Window Over the String**:
   If the string is sufficiently long (i.e., its size is greater than or equal to 10), we proceed with a sliding window approach. We iterate over the string from index 0 to `s.size() - 10` (ensuring we don’t go past the end of the string). For each index `i`, we extract a 10-character substring using `substr(i, 10)`.

   ```cpp
   for (size_t i = 0; i <= s.size() - 10; ++i) {
       auto substr = s.substr(i, 10);
   ```

   - **`substr(i, 10)`**: This function call extracts a substring starting at position `i` with length 10. It’s like a sliding window of length 10 that moves one character at a time along the string.

4. **Track Substrings in the Hash Map**:
   For each extracted substring, we attempt to insert it into the map using `try_emplace`. If the substring is not yet in the map, we insert it with a count of 1. If it’s already in the map, we increment its count.

   ```cpp
   auto [it, success] = map.try_emplace(std::move(substr), 1);
   if (!success) ++it->second;
   ```

   - **`try_emplace(substr, 1)`**: Attempts to insert the substring into the map with an initial count of 1. If it already exists, `success` is `false`, and we increment its count.

5. **Check for Repeated Substrings**:
   If a substring's count reaches exactly 2 (i.e., it has been seen exactly twice), we add it to the result vector `res`. The key here is the check for **exactly 2 occurrences**: this ensures that we only add the substring the first time it is repeated, avoiding duplicates in the result.

   ```cpp
   if (it->second == 2) res.emplace_back(it->first);
   ```

   - **Why exactly 2?**: This check ensures that a substring is only added to the result list once, even if it appears more than twice in the input string. We only care about the fact that it has been repeated, and adding it the first time it reaches a count of 2 avoids unnecessary duplicates in the final result.

6. **Return the Result**:
   After processing all possible substrings, the `res` vector contains all substrings that appear at least twice in the input string `s`. We return this vector as the result.

   ```cpp
   return res;
   ```

## Key Insights:

- **Sliding Window**:
  - The algorithm effectively simulates a sliding window of size 10 over the string `s`, extracting each 10-character substring as it progresses.

- **Efficient Substring Tracking**:
  - By using an `unordered_map`, we efficiently track the count of each substring in constant time on average, making the process of checking and updating the counts very efficient.

- **Avoiding Duplicate Results**:
  - The result vector `res` is populated only when a substring has been seen exactly twice. This ensures that we avoid adding duplicate substrings, even if they appear more than twice in the input string.

- **Time Complexity**:
  - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the input string `s`. This is because we are iterating through the string once, and each substring operation (insertion and lookup in the map) takes constant time on average.
  - **Space Complexity**: The space complexity is **O(n)**, where `n` is the number of possible substrings of length 10 in the string. In the worst case, each substring could be unique, leading to a space usage proportional to the number of substrings.

---

## Final Thoughts:

This solution efficiently finds repeated DNA sequences (substrings of length 10) using a sliding window and an unordered map for constant-time tracking. By only adding substrings to the result once they are seen exactly twice, we ensure that we avoid duplicates in the result, even if the substring occurs more than twice. The algorithm operates in **O(n)** time and **O(n)** space, making it an efficient and scalable solution for this problem.
