# Longest Valid Parentheses: Problem Explanation and Solution

This solution calculates the length of the longest valid parentheses substring in a given string. It uses a **stack** to efficiently keep track of the indices of unmatched parentheses and to compute the length of valid substrings.

## Problem Overview:

### Input:
A string `s` consisting of only the characters `'('` and `')'`.

### Output:
The length of the longest valid parentheses substring.

For example:
- **Input**: `"()(()()(()("`
- **Output**: `4`  
  (Explanation: The longest valid parentheses substring is `()()` at indices 2–5.)

- **Input**: `"(()"`
- **Output**: `2`  
  (Explanation: The longest valid parentheses substring is `()` at indices 0–1.)

- **Input**: `")()())"`
- **Output**: `4`  
  (Explanation: The longest valid parentheses substring is `()()` at indices 1–4.)

---

## Step-by-Step Explanation:

### 1. **Initialize the Stack**:
   - A stack is used to store the indices of unmatched opening parentheses `(`, and it helps in calculating the length of valid parentheses when a closing parenthesis `)` is encountered.
   - We initialize the stack with `-1` as a base value to handle edge cases like when the entire string is a valid parentheses string.

   ```cpp
   std::stack<int> st;
   st.emplace(-1);  // Initial base value to calculate lengths correctly
   int max_len = 0;  // Variable to track the maximum length
   ```

### 2. **Iterate Through the String**:
   We loop through each character in the string `s` to identify valid parentheses pairs:

   - **When encountering an opening parenthesis `(`**:  
     Push its index onto the stack.
   
     ```cpp
     if (s[i] == '(') {
         st.emplace(static_cast<int>(i));
     }
     ```

   - **When encountering a closing parenthesis `)`**:  
     Pop the top of the stack. This will either:
     - Match with the most recent unmatched opening parenthesis, or
     - Pop the base value `-1` if there is no match.

     If the stack is empty after popping, it means there is no valid substring from the current position, so we push the current index onto the stack to mark the new base for valid substrings.

     If the stack is not empty after popping, it means we have found a valid parentheses substring. We compute its length by subtracting the current index with the index at the top of the stack. We then update `max_len` if this new length is greater than the current `max_len`.

     ```cpp
     else {
         st.pop();  // Pop the top to check for a valid pair
         if (st.empty()) {
             st.emplace(static_cast<int>(i));  // Set the new base if stack is empty
         } else {
             max_len = std::max(max_len, static_cast<int>(i) - st.top());  // Update max_len
         }
     }
     ```

### 3. **Return the Result**:
   After processing the entire string, the `max_len` variable contains the length of the longest valid parentheses substring, which we return.

   ```cpp
   return max_len;
   ```

---

### 4. **Edge Case Handling**:
   - **Empty String**: If the input string is empty, the result is 0, as no valid parentheses exist.
   - **Unmatched Parentheses**: The algorithm correctly handles unmatched parentheses by using the stack to track indices and adjusting accordingly.
   - **Entire String is Valid**: If the entire string is a valid parentheses substring, the algorithm handles it by continuously updating the `max_len`.

   For example:
   - **Input**: `"()(()()(()("`  
     The longest valid substring is `()()` from indices 2–5, so the output is `4`.
   
   - **Input**: `"(()"`  
     The longest valid substring is `()` from indices 0–1, so the output is `2`.

---

## Time and Space Complexity:

- **Time Complexity**:  
  The algorithm runs in **O(n)** time, where `n` is the length of the string `s`. Each character in the string is processed once, and each operation with the stack (push and pop) takes constant time.

- **Space Complexity**:  
  The space complexity is **O(n)**, where `n` is the length of the string. In the worst case, the stack may store all indices of the string (if all characters are `(`).

---

## Final Thoughts:

This solution efficiently computes the length of the longest valid parentheses substring using a **stack** to track indices. The algorithm runs in linear time (**O(n)**) and requires linear space (**O(n)**) due to the stack. By handling both matched and unmatched parentheses in a systematic way, the solution is able to handle various edge cases and perform well even for longer input strings.
