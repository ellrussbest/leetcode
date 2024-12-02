# Decode String: Problem Explanation and Solution

This solution decodes a string that is encoded with patterns like `k[sub_string]`, where `k` is a positive integer that tells us how many times to repeat the enclosed `sub_string`. The solution uses a stack to handle nested patterns efficiently.

## Problem Overview:

### Input:
A string `s` containing an encoded pattern where substrings are enclosed in square brackets. Each encoded pattern follows the format `k[sub_string]`, where `k` is a non-negative integer and `sub_string` can be another string, possibly containing nested encodings.

### Output:
The function returns the fully decoded string.

For example:
- **Input**: `"3[a]2[bc]"`
- **Output**: `"aaabcbc"`

- **Input**: `"3[a2[c]]"`
- **Output**: `"accaccacc"`

- **Input**: `"2[abc]3[cd]ef"`
- **Output**: `"abcabccdcdcdef"`

---

## Step-by-Step Explanation:

### 1. **Initialize Variables**:
   - We use a stack to store pairs of values: the first element is the number (repeat count), and the second element is the string encountered before an open bracket `[`.
   - We maintain a string `curr_string` that builds up the current decoded string and an integer `count` to keep track of the repeat count for the current segment.

   ```cpp
   std::stack<std::pair<int, std::string>> st;
   std::string curr_string{};
   int count = 0;
   ```

### 2. **Iterate Through the String**:
   We loop over each character `ch` in the string `s` and handle it differently based on its value:

   - **When encountering a digit (`0-9`)**: This indicates the repeat count for the next substring enclosed in `[]`. We build the repeat count by adjusting `count` for multi-digit numbers.
   
     ```cpp
     if (std::isdigit(ch)) {
         count = count * 10 + (ch - '0');
     }
     ```

   - **When encountering an opening bracket `[`**: This signifies the start of an encoded pattern. We push the current repeat count (`count`) and the current string (`curr_string`) onto the stack, and reset `curr_string` to start collecting the new substring.
   
     ```cpp
     if (ch == '[') {
         st.emplace(count, curr_string);
         curr_string.clear();
         count = 0;
     }
     ```

   - **When encountering a closing bracket `]`**: This marks the end of a substring to be repeated. We pop the top of the stack, which gives us the previous string and the repeat count. We repeat `curr_string` as specified by the count and concatenate it to the previous string to form the new `curr_string`.
   
     ```cpp
     else if (ch == ']') {
         auto& [prev_count, prev_string] = st.top();
         std::string decoded{};
         for (int i = 0; i < prev_count; ++i) {
             decoded += curr_string;
         }
         curr_string = std::move(prev_string) + decoded;
         st.pop();
     }
     ```

   - **When encountering a letter (non-digit and non-bracket)**: This is part of the substring we are building. We simply append it to `curr_string`.
   
     ```cpp
     else {
         curr_string += ch;
     }
     ```

### 3. **Return the Result**:
   After processing all characters, `curr_string` holds the fully decoded string, which is then returned.

   ```cpp
   return curr_string;
   ```

---

### 4. **Edge Case Handling**:
   - **Empty Input**: If the input string is empty, the algorithm will return an empty string without any issues.
   - **No Encoded Patterns**: If the string does not contain any encoded patterns (i.e., no square brackets), the function will return the string as it is.
   - **Nested Encodings**: The algorithm efficiently handles nested encodings by utilizing the stack to maintain the context of each level of nesting.
   
   For example:
   - **Input**: `"3[a2[c]]"`
   - **Steps**: The algorithm processes `a2[c]` and decodes it as `acc`, then repeats it 3 times to produce `accaccacc`.

---

## Time and Space Complexity:

- **Time Complexity**:  
  - The algorithm runs in **O(n)** time, where `n` is the length of the input string `s`. Each character is processed once, and all operations inside the loop (push, pop, string concatenation) are constant time operations.

- **Space Complexity**:  
  - The space complexity is **O(n)** due to the stack, which can store at most `O(n)` entries (in the worst case, if the string has deeply nested patterns). Additionally, the space used by `curr_string` also contributes to the space complexity.

---

## Final Thoughts:

This solution decodes strings with nested patterns by using a stack to manage different levels of encoding. The approach is both time-efficient (**O(n)**) and space-efficient (**O(n)**). By iterating through the string once and utilizing the stack to handle nested substrings, the algorithm decodes complex patterns reliably.
