# Reverse Words in a String: Problem Explanation and Solution

This solution takes a string `s`, reverses the order of the words in it, and returns the modified string. It handles edge cases like leading/trailing spaces and multiple spaces between words. The approach uses a combination of standard library functions like `std::reverse`, `std::find_if`, and `std::unique` to efficiently process the string.

## Problem Overview:

### Input:
A string `s`, which contains words separated by spaces. The string may contain leading, trailing, or multiple spaces between words.

### Output:
A string where the words are reversed in order, with no extra spaces between words and no leading/trailing spaces.

For example:
- **Input**: `"the sky is blue"`
- **Output**: `"blue is sky the"`

- **Input**: `"  hello world  "`
- **Output**: `"world hello"`

- **Input**: `"a good   example"`
- **Output**: `"example good a"`

---

## Step-by-Step Explanation:

### 1. **Trim Leading and Trailing Spaces**:
   The first step is to remove any leading or trailing spaces from the string. This is done using two helper functions: `ltrim` and `rtrim`.

   - **ltrim** removes spaces from the beginning of the string.
   - **rtrim** removes spaces from the end of the string.

   ```cpp
   void trim(std::string& s) {
       ltrim(s);
       rtrim(s);
   }

   void ltrim(std::string& s) {
       auto it = std::find_if_not(s.begin(), s.end(), [](const unsigned char& c) { return std::isspace(c); });
       s.erase(s.begin(), it);
   }

   void rtrim(std::string& s) {
       auto it = std::find_if_not(s.rbegin(), s.rend(), [](const unsigned char& c) { return std::isspace(c); });
       s.erase(it.base(), s.end());
   }
   ```

   - `std::find_if_not`: Finds the first character that is not a space, starting from either the beginning (for `ltrim`) or the end (for `rtrim`).
   - `erase`: Removes the range of characters before or after the space.

### 2. **Reverse the Entire String**:
   After trimming, we reverse the entire string. This is a simple step using the `std::reverse` algorithm to prepare for reversing the words in the string.

   ```cpp
   std::reverse(s.begin(), s.end());
   ```

   Reversing the entire string helps in handling the words in reverse order, which is the desired final result.

### 3. **Reverse Each Word**:
   After reversing the entire string, we proceed to reverse each word individually. The approach here is to:
   - Use `std::find_if_not` to find the start of the word (skipping any spaces).
   - Use `std::find_if` to find the end of the word.
   - Reverse the word in-place using `std::reverse`.

   This is done in a loop for each word:

   ```cpp
   auto start = s.begin();
   while (start != s.end()) {
       start = std::find_if_not(start, s.end(), [](const unsigned char& c) { return std::isspace(c); });
       auto end = std::find_if(start, s.end(), [](const unsigned char& c) { return std::isspace(c); });
       std::reverse(start, end);
       start = end;
   }
   ```

   - `std::find_if_not`: Finds the first non-space character to mark the start of a word.
   - `std::find_if`: Finds the first space character after the start of the word, marking the end of the word.
   - `std::reverse`: Reverses the word between the start and end iterators.

### 4. **Remove Extra Spaces Between Words**:
   After reversing the individual words, there may be multiple spaces between them. We clean this up using `std::unique`, which removes consecutive spaces, and then erase the extra spaces.

   ```cpp
   void removeExtraSpaces(std::string& s) {
       auto it = std::unique(s.begin(), s.end(), [](char lhs, char rhs) {
           return std::isspace(lhs) && std::isspace(rhs);
       });
       s.erase(it, s.end());
   }
   ```

   - `std::unique`: Removes consecutive duplicate characters, which in this case are spaces. It ensures that only a single space remains between words.
   - `erase`: Removes the extra spaces from the string after `std::unique` has identified them.

### 5. **Return the Result**:
   The final step is to return the modified string.

   ```cpp
   return s;
   ```

---

## Time and Space Complexity:

- **Time Complexity**:
  - **O(n)**: The time complexity of the solution is linear in terms of the length of the string `n` because each major operation (trimming, reversing, and word reversal) runs in **O(n)** time.
  
- **Space Complexity**:
  - **O(1)**: The solution uses a constant amount of extra space since all modifications are done in place, without allocating additional memory for data structures (other than the input string).

---

## Final Thoughts:

This solution efficiently reverses the words in a string while handling edge cases like leading/trailing spaces and extra spaces between words. The algorithm is time-efficient with **O(n)** complexity and uses constant extra space, making it suitable for processing longer strings. By using standard library functions like `std::reverse` and `std::find_if`, the solution is both clean and efficient.