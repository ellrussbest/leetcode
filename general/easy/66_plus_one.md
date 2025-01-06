# `plusOne` Solution: Intuition

This solution solves the problem of adding one to a number represented as a vector of digits. The vector holds the digits of the number in order, and the goal is to increment this number by one.

## Step-by-Step Explanation:

1. **Initialization**:
   - A `carry` variable is initialized to `1` because we're adding 1 to the number.
   - The vector `digits` is processed from the least significant digit (rightmost) to the most significant (leftmost).

   ```cpp
   int carry = 1;
   ```

2. **Iterate and Process Each Digit**:
   - We iterate through the digits using a reverse iterator (`rbegin` to `rend`), starting from the rightmost digit.
   - For each digit:
     - Add the `carry` (starting as 1) to the current digit.
     - Calculate the new digit by taking the modulo 10 of the sum.
     - Update the `carry` to be the integer division of the sum by 10 (i.e., if the sum is greater than or equal to 10, the carry will be 1).
     - If no carry remains (`carry == 0`), we break the loop early to save unnecessary iterations.

   ```cpp
   for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
       auto prev = *it;
       *it = (prev + carry) % 10;
       carry = (prev + carry) / 10;

       if (carry == 0)
           break;
   }
   ```

3. **Handle Overflow**:
   - If after processing all digits there is still a `carry` left (i.e., the number was something like 999), we insert the `carry` (which will be 1) at the front of the vector.
   
   ```cpp
   if (carry == 1)
       digits.insert(digits.begin(), carry);
   ```

4. **Return Result**:
   - The modified `digits` vector is returned, representing the incremented number.

   ```cpp
   return digits;
   ```

5. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because we iterate through the vector of digits once, where `n` is the number of digits.
   - **Space Complexity**: The space complexity is **O(1)** if we ignore the space used by the input vector, as we modify the input in place and only use a few extra variables (`carry` and `it`).

## Key Insights:

- **Efficient Digit Processing**:
  - The solution processes the digits from right to left, which is the natural order for addition in base-10 arithmetic.
  
- **Carry Handling**:
  - The carry is propagated from the least significant to the most significant digit, which mimics the behavior of addition in normal arithmetic.

- **Edge Case Handling**:
  - The solution properly handles edge cases like numbers that require an extra digit (e.g., `999 + 1 = 1000`).

## Final Thoughts:

This `plusOne` solution is efficient, with **O(n)** time complexity, and handles the increment operation by iterating through the digits in reverse order. It efficiently manages carries and can handle overflow, ensuring correctness even in cases like carrying over from `9` to `10`. The solution has a space complexity of **O(1)**, excluding input space, making it an optimal approach for this problem.
