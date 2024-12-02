# Check if Two Strings are Anagrams: Problem Explanation and Solution

This solution determines if two strings are anagrams by comparing the frequency of characters in both strings. It uses an array to count occurrences of each letter and checks if both strings have the same letter frequencies.

## Problem Overview:

### Input:
Two strings `s` and `t`.

### Output:
- **True** if the strings are anagrams.
- **False** if the strings are not anagrams.

For example:
- **Input**: `"anagram", "nagaram"`
- **Output**: `true`  
  (Explanation: Both strings have the same characters with the same frequency.)

- **Input**: `"rat", "car"`
- **Output**: `false`  
  (Explanation: The strings have different characters.)

---

## Step-by-Step Explanation:

### 1. **Check if the Strings Have Equal Length**:
   The first step is to check if the strings `s` and `t` have the same length. If they don't, they can't be anagrams, so we return `false`.

   ```cpp
   if (s.size() != t.size()) return false;
   ```

### 2. **Initialize a Frequency Count Array**:
   To count the occurrences of each character in the strings, we use a `std::vector<int>` of size 26, initialized to zero. This array represents the frequency of each letter from 'a' to 'z'.

   ```cpp
   std::vector<int> count(26, 0);  // Array to store frequency counts for 'a' to 'z'
   ```

### 3. **Count Characters in String `s`**:
   We iterate through each character in string `s` and increment the corresponding index in the `count` array. The index is calculated by subtracting `'a'` from the character to map it to a position in the array (`'a'` corresponds to index 0, `'b'` to index 1, etc.).

   ```cpp
   for (char c : s) {
       ++count[static_cast<size_t>(c - 'a')];  // Increment count for character 'c'
   }
   ```

### 4. **Decrement Counts for Characters in String `t`**:
   Next, we iterate through each character in string `t`. For each character, we decrement the corresponding count in the `count` array. If any count goes below zero, it means `t` contains more occurrences of that character than `s`, so the strings can't be anagrams, and we return `false`.

   ```cpp
   for (char c : t) {
       if (--count[static_cast<size_t>(c - 'a')] < 0) {
           return false;  // Return false if count goes negative (extra character in t)
       }
   }
   ```

### 5. **Return True**:
   If we successfully process both strings without finding any discrepancies, it means the strings are anagrams, so we return `true`.

   ```cpp
   return true;
   ```

---

## Time and Space Complexity:

- **Time Complexity**:
  - **O(n)**: The time complexity is linear in terms of the length of the strings `n`. We iterate through each character of both strings exactly once (two passes), and each operation inside the loop takes constant time.
  
- **Space Complexity**:
  - **O(1)**: The space complexity is constant since we use a fixed-size array of 26 elements to count the character frequencies (independent of the size of the input strings).

---

## Final Thoughts:

This solution efficiently checks if two strings are anagrams by counting the frequency of characters. With a time complexity of **O(n)** and constant space complexity **O(1)** (due to the fixed array size), the solution is both time-efficient and space-efficient. It handles all edge cases, such as different string lengths, and works well even for large strings.