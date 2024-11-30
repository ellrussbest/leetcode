# isValid Solution: Intuition

This solution validates if a string containing brackets (i.e., parentheses `()`, square brackets `[]`, and curly braces `{}`) is correctly balanced. The solution uses a **stack** to ensure that each closing bracket corresponds to the most recent unmatched opening bracket, following the Last In, First Out (LIFO) principle.

## Step-by-Step Explanation:

### 1. **Initialize a Stack**:
   A stack is used to track the opening brackets as they appear. The stack will help ensure that each closing bracket matches the latest opening bracket.

   ```cpp
   std::stack<char> st;
   ```

### 2. **Iterate Over the String**:
   We iterate over each character in the string `s`. For each character:
   - If it's a closing bracket (`}`, `)`, `]`), we check if there is a corresponding opening bracket in the stack.
   - If it's an opening bracket (`{`, `(`, `[`), we push it onto the stack.

   ```cpp
   for (const auto& c : s) {
       if (is_closing_brackets(c)) {
           if (st.empty()) return false;
           auto it = m_pairs.find(c);
           if (it->second != st.top()) return false;
           st.pop();
       } else {
           st.emplace(c);
       }
   }
   ```

### 3. **Check for Matching Brackets**:
   - If a closing bracket is found, the algorithm checks if the stack is not empty and if the top of the stack matches the corresponding opening bracket for the current closing bracket.
   - If they don't match, the string is invalid, and the function returns `false`.

   ```cpp
   if (st.empty()) return false;
   auto it = m_pairs.find(c);
   if (it->second != st.top()) return false;
   st.pop();
   ```

### 4. **Return the Result**:
   After iterating through the entire string, the function checks if the stack is empty. If the stack is empty, all brackets have been correctly matched and closed, so the string is valid. Otherwise, the string is invalid.

   ```cpp
   return st.empty();
   ```

### 5. **Helper Function - is_closing_brackets**:
   The function `is_closing_brackets` determines if a character is a closing bracket. This helps streamline the main logic by separating the check for closing brackets into its own function.

   ```cpp
   bool is_closing_brackets(const char& c) {
       return c == '}' || c == ')' || c == ']';
   }
   ```

### 6. **Bracket Pair Mapping**:
   A hash map (`unordered_map`) is used to store the pairs of matching brackets. This allows quick lookup for matching opening brackets when processing closing brackets.

   ```cpp
   std::unordered_map<char, char> m_pairs{
       {'}', '{'},
       {')', '('},
       {']', '['},
   };
   ```

## Key Insights:

- **Stack-Based Approach**:
  - The stack efficiently ensures that the brackets are matched in the correct order. Every time a closing bracket is encountered, the stack provides the most recent unmatched opening bracket to check for a valid pair.
  
- **Early Exit**:
  - If a mismatch is found early (either a closing bracket without a corresponding opening bracket or a mismatch between brackets), the function returns `false` immediately, optimizing performance.
  
- **Edge Case Handling**:
  - If the string contains any unbalanced brackets or mismatched pairs, the algorithm correctly returns `false`.
  - If the string is empty or all brackets are correctly matched, the function returns `true`.

## Time and Space Complexity:

- **Time Complexity**: The algorithm runs in **O(n)** time, where `n` is the length of the string. Each character is processed once, and each stack operation (push or pop) takes constant time.
  
- **Space Complexity**: The space complexity is **O(n)**, where `n` is the maximum depth of the stack. In the worst case, when all characters are opening brackets, the stack will hold all of them.

## Final Thoughts:

The stack-based approach is an efficient way to solve the problem of validating bracket balance. By leveraging the LIFO property of stacks, the solution ensures that brackets are matched and closed in the correct order. This solution has optimal time and space complexity for this problem, making it suitable for large inputs.
