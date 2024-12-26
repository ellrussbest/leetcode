# isValid Solution: Intuition

This solution checks if a string containing parentheses is valid, meaning each opening parenthesis has a corresponding closing parenthesis, and the pairs are correctly nested. The solution uses a stack to track unmatched opening parentheses and matches them with closing ones as they appear.

## Step-by-Step Explanation:

1. **Pair Mapping**:
   - A static `unordered_map` named `pairs` is used to map each closing parenthesis to its corresponding opening parenthesis. This helps in quickly finding the matching opening parenthesis when we encounter a closing parenthesis in the string.

   ```cpp
   static std::unordered_map<char, char> pairs{
       {')', '('},
       {'}', '{'},
       {']', '['},
   };
   ```

2. **Stack Initialization**:
   - A stack `st` is used to track opening parentheses. When we encounter an opening parenthesis (`'('`, `'{'`, `'['`), it is pushed onto the stack.

   ```cpp
   std::stack<char> st;
   ```

3. **Iterate Through String**:
   - For each character `c` in the input string `s`:
     - If `c` is a closing parenthesis (i.e., it exists in the `pairs` map), check if the stack is empty or if the top of the stack does not match the corresponding opening parenthesis. If either condition is true, the string is invalid, and we return `false`.
     - If `c` is an opening parenthesis, push it onto the stack.

   ```cpp
   for (const auto& c : s) {
       if (auto it = pairs.find(c); it != pairs.end()) {
           if (st.empty() || it->second != st.top())
            return false;
           st.pop();
       } else {
           st.emplace(c);
       }
   }
   ```

4. **Final Check**:
   - After processing all characters, if the stack is empty, it means all parentheses have been matched, and we return `true`. If the stack is not empty, it indicates unmatched opening parentheses, and we return `false`.

   ```cpp
   return st.empty();
   ```

5. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the string. We iterate over each character in the string once, and the operations with the stack (push, pop, top) are all constant time operations.
   - **Space Complexity**: The space complexity is **O(n)** due to the stack used to store unmatched opening parentheses.

## Key Insights:

- **Stack Usage**:
  - The stack is essential for efficiently tracking and matching opening and closing parentheses. As we encounter a closing parenthesis, we simply pop the corresponding opening parenthesis from the stack if it matches. If not, the string is immediately deemed invalid.

- **Efficient Lookup**:
  - The use of `unordered_map` for storing matching pairs allows for efficient lookup when processing each character in the string. This avoids the need for nested loops or more complex matching logic.

- **Edge Cases**:
  - The solution handles edge cases like unmatched parentheses and incorrect nesting efficiently. For example, the input `"(]"` returns `false`, indicating invalid parentheses.

## Final Thoughts:

This `isValid` solution efficiently checks if the parentheses in a string are balanced in **O(n)** time and **O(n)** space. It leverages the stack data structure and a hash map for constant-time matching of parentheses, providing a simple yet effective approach for this problem.
