# fizzBuzz Solution: Intuition

This solution generates a list of strings for the numbers from 1 to `n`. For each number:
- If the number is divisible by 3, it outputs "Fizz".
- If the number is divisible by 5, it outputs "Buzz".
- If the number is divisible by both 3 and 5, it outputs "FizzBuzz".
- Otherwise, it outputs the number itself.

## Step-by-Step Explanation:

1. **Initialization**:
   - We create a vector `res` of size `n` to hold the results.
   - The number `n` is cast to `size_t` to avoid potential issues with integer types.

   ```cpp
   size_t N = static_cast<size_t>(n);
   std::vector<std::string> res(N);
   ```

2. **Iterate and Construct Strings**:
   - We loop from `0` to `n-1` (size of the vector). For each index `i`, we:
     - Create an empty string `s`.
     - Check if the number `(i + 1)` is divisible by 3 and/or 5. If so, append "Fizz" and/or "Buzz" to `s`.
     - If neither condition is true, we convert `(i + 1)` to a string and assign it to `s`.

   ```cpp
   for (size_t i = 0; i < N; ++i) {
       std::string s{};
       if ((i + 1) % 3 == 0)
        s += "Fizz";
       if ((i + 1) % 5 == 0)
        s += "Buzz";
       if (s.size() == 0)
        s += std::to_string((i + 1));
       res[i] = std::move(s);
   }
   ```

3. **Return Result**:
   - Once the loop is complete, the vector `res` containing the result strings is returned.

   ```cpp
   return res;
   ```

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because we loop through the numbers from `1` to `n`, performing constant-time operations for each number.
   - **Space Complexity**: The space complexity is **O(n)** because we store the result in a vector of size `n`.

## Key Insights:

- **Modulo Checks**:
  - The solution uses the modulo operator (`%`) to determine divisibility by 3 and 5, which is efficient for generating the "Fizz" and "Buzz" strings.

- **Efficient String Construction**:
  - String concatenation (`+=`) is used to build the results dynamically. This ensures that we append only relevant strings ("Fizz", "Buzz", or the number itself).

- **Space Complexity**:
  - The solution creates a vector of size `n` to store the results, making the space complexity **O(n)**, which is optimal for this problem.

## Final Thoughts:

This `fizzBuzz` solution generates the correct sequence of strings in **O(n)** time and **O(n)** space. It efficiently handles the logic for checking divisibility by 3, 5, and both, providing a simple and effective approach for generating the "FizzBuzz" sequence.
