# Balanced String Split Solution: Intuition

This solution determines the number of balanced substrings in a given string. A balanced substring is defined as one that contains an equal number of 'L' and 'R' characters. The goal is to find how many such balanced substrings can be formed from the given string.

## Step-by-Step Explanation:

1. **Initialization**:
   - We define three variables:
     - `r` to count the number of 'R' characters in the current substring.
     - `l` to count the number of 'L' characters in the current substring.
     - `res` to store the number of balanced substrings found.
   - Initially, both `r` and `l` are set to 0, and `res` is also initialized to 0.

   ```cpp
   int r = 0;
   int l = 0;
   int res = 0;
   ```

2. **Iterate Through the String**:
   - We loop through each character in the string:
     - If the counts of 'L' and 'R' are equal (`r == l`), it means we have found a balanced substring. We increment `res`, and reset both `r` and `l` to 0 to start counting the next substring.
     - If the character is 'L', we increment `l`. If it's 'R', we increment `r`.

   ```cpp
   for (const auto& c : s) {
       if (r > 0 && l > 0 && r == l) {
           ++res;
           r = 0;
           l = 0;
       }

       if (c == 'L')
           ++l;
       else
           ++r;
   }
   ```

3. **Final Check**:
   - After the loop, if `r == l`, it means the last substring is also balanced, so we increment `res` one last time to account for it.

   ```cpp
   if (r == l)
       ++res;
   ```

4. **Return Result**:
   - Finally, we return `res`, which holds the total count of balanced substrings.

   ```cpp
   return res;
   ```

5. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the string. We iterate through the string once, performing constant-time operations for each character.
   - **Space Complexity**: The space complexity is **O(1)** since we use only a few integer variables to keep track of counts, regardless of the size of the input string.

## Key Insights:

- **Greedy Approach**:
  - This solution uses a greedy approach to find balanced substrings. Every time the counts of 'L' and 'R' match, we count it as a balanced substring and reset the counters.

- **Efficient Pair Counting**:
  - By simply counting occurrences of 'L' and 'R', we efficiently track the balance without needing extra space or complex data structures.

- **Edge Cases**:
  - The algorithm handles cases where there are no balanced substrings by returning 0, and it also correctly counts substrings even if the entire string is balanced.

## Final Thoughts:

The `balancedStringSplit` solution is efficient with a linear time complexity of **O(n)** and constant space complexity **O(1)**. It efficiently counts the number of balanced substrings using a simple counting approach.
