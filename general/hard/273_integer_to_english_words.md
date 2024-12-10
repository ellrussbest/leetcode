# numberToWords Solution: Intuition

This solution converts a given integer `num` into its English words representation. It handles numbers up to the billions range and formats them properly by breaking them down into smaller groups of thousands, millions, etc. The solution ensures that each group of digits is processed recursively, and non-significant trailing spaces are trimmed from the final result.

## Step-by-Step Explanation:

1. **Initialization**:
   - We begin by checking if the input number `num` is `0`. If it is, we return the string `"Zero"`.
   - An empty string `res` is initialized to build the final result. We also initialize an index `idx` that helps us keep track of the appropriate grouping (thousands, millions, etc.).

   ```cpp
   if (num == 0) return "Zero";
   std::string res{};
   size_t idx = 0;
   ```

2. **Iterate Over Groups of Thousands**:
   - The main loop processes the number in chunks of 1000 (thousands, millions, billions). For each group:
     - We check if the current group (`num % 1000`) is non-zero. If so, we convert it into words using the `helper` function, append the appropriate thousand group (e.g., "Thousand", "Million"), and prepend it to `res`.

   ```cpp
   while (num > 0) {
       if (num % 1000 != 0) {
           std::string tmp{};
           helper(tmp, static_cast<size_t>(num) % 1000);
           tmp += thousands[idx];
           tmp += " ";
           res = std::move(tmp) + res;
       }
       ++idx;
       num /= 1000;
   }
   ```

3. **Calling the Helper Function**:
   - The `helper` function is responsible for converting a number (less than 1000) into words.
   - It works recursively:
     - If the number is less than 20, it directly appends the corresponding word from the `less_than_twenty` array.
     - If the number is between 20 and 99, it adds the appropriate tens place from the `tens` array and recursively handles the ones place.
     - If the number is 100 or more, it adds the corresponding hundreds place and recursively processes the remainder.

   ```cpp
   void helper(std::string& s, size_t num) {
       if (num == 0) return;
       else if (num < 20) {
           s += less_than_twenty[num];
           s += " ";
           return;
       } else if (num < 100) {
           s += tens[num / 10];
           s += " ";
           helper(s, num % 10);
       } else {
           s += less_than_twenty[num / 100];
           s += " Hundred ";
           helper(s, num % 100);
       }
   }
   ```

4. **Trimming the Result**:
   - After constructing the number in words, we call the `rtrim` function to remove any trailing spaces from the result.

   ```cpp
   rtrim(res);
   ```

5. **Return the Result**:
   - Finally, we return the fully formatted string `res`, which contains the English words representation of the input number.

   ```cpp
   return res;
   ```

## Key Insights:

- **Recursive Breakdown**:
  - The solution recursively breaks down the number into groups of hundreds, tens, and ones, leveraging smaller base cases for numbers less than 20, and then combining those results with appropriate group names like "Thousand", "Million", etc.

- **Edge Case Handling**:
  - The function correctly handles the edge case of `0`, immediately returning `"Zero"`.
  - It also handles large numbers up to billions by breaking them down into smaller manageable chunks.

- **Space Complexity**:
  - The space complexity is **O(1)** beyond the input/output, as the function operates using only a fixed number of arrays for group names and a small number of integer variables (`num`, `idx`, `tmp`).

---

## Example Walkthrough:

Consider the input `1234567891`:

1. The loop starts with `num = 1234567891` and processes groups of thousands.
   - First group: `123` → `"One Hundred Twenty Three "`
   - Second group: `456` → `"Four Hundred Fifty Six "`
   - Third group: `789` → `"Seven Hundred Eighty Nine "`
   - Fourth group: `1` → `"One "`

2. These are combined with appropriate thousands, millions, and billions:
   - `"One Billion Four Hundred Fifty Six Million Seven Hundred Eighty Nine Thousand One Hundred Twenty Three "`

3. The final result is trimmed of trailing spaces and returned.

---

## Final Thoughts:

This `numberToWords` solution efficiently converts an integer into its English words representation by breaking the number into manageable chunks (thousands, millions, etc.) and recursively converting each chunk. The solution handles both large numbers and edge cases effectively, while ensuring that the result is correctly formatted.