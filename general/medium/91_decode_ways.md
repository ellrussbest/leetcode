# Decode Ways Problem: Solution and Intuition

The problem involves decoding a string where each character is a digit between '1' and '9' (representing 'A' to 'I'), and pairs of digits between '10' and '26' represent letters 'J' to 'Z'. The task is to determine how many ways the string can be decoded.

## Problem Breakdown:

1. **Input**: A string `s` consisting of digits between '0' and '9'.
2. **Output**: The number of ways the string can be decoded into letters, adhering to the rules mentioned above.

## Step-by-Step Explanation:

### 1. **Initialization**:
   - A helper function `helper` is defined to compute the number of decodings for the string, using recursion and memoization to improve performance.
   - An unordered map `memo` is used to store results for previously encountered substrings of `s`, which prevents redundant calculations.

   ```cpp
   std::unordered_map<std::string, int> memo;
   return helper(s, memo); 
   ```

### 2. **Recursive Helper Function**:
   - The base case checks if the string is empty (`s.size() == 0`), which indicates there is exactly one way to decode (return 1).
   - If the string starts with '0', it's invalid since '0' cannot map to any letter, so it returns 0.
   
   ```cpp
   if(s.size() == 0)
       return 1;
   if(s[0] == '0')
       return 0;
   ```

   - If the result for the current substring `s` has been computed before (found in `memo`), it is directly returned to avoid recomputation.

   ```cpp
   if(auto it = memo.find(s); it != memo.end())
       return it->second;
   ```

   - The recursive cases involve:
     - **One character decoding**: If the string has at least one character, we recursively decode the remaining string starting from the second character (`s.substr(1)`).
     - **Two character decoding**: If the string has at least two characters, we check if the first two characters form a valid number between 10 and 26 (inclusive). If so, we recursively decode the rest of the string starting from the third character (`s.substr(2)`).

   ```cpp
   if(s.size() >= 1)
       count += helper(s.substr(1), memo);
   
   if(s.size() >= 2
       && std::stoi(s.substr(0, 2)) >= 10
       && std::stoi(s.substr(0, 2)) <= 26)
       count += helper(s.substr(2), memo);
   ```

   - After computing the total number of decodings for the current substring, we store the result in `memo` to avoid recomputation and then return the count.

   ```cpp
   memo.try_emplace(s, count);
   return count;
   ```

### 3. **Return the Result**:
   - The `numDecodings` function calls `helper` to calculate the result for the entire string `s` and returns the final count.
   
   ```cpp
   std::cout << Solution{}.numDecodings("12") << "\n";  // Outputs: 2
   std::cout << Solution{}.numDecodings("226") << "\n";  // Outputs: 3
   ```

### 4. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the string. Each unique substring of `s` is computed only once, thanks to memoization.
   - **Space Complexity**: The space complexity is **O(n)** due to the space required for the `memo` map and the recursive call stack.

## Key Insights:

- **Memoization**:
  - The solution uses memoization to store the results of subproblems (i.e., the number of ways to decode substrings), ensuring that the same substring is not processed multiple times.
  
- **Recursive Structure**:
  - The problem is naturally recursive: each substring can be decoded either by considering the first character alone or the first two characters together (if valid).
  
- **Base Cases**:
  - Proper handling of invalid cases (e.g., strings starting with '0') and the empty string ensures the solution works correctly for all input cases.

## Final Thoughts:

This solution efficiently computes the number of ways to decode a string using **O(n)** time and **O(n)** space. By leveraging memoization, it avoids redundant calculations and provides an optimal approach for solving this problem.
