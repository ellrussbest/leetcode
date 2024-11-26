# reverse Solution: Intuition

This solution takes a signed 32-bit integer `x` and returns its digits in reverse order. If reversing the integer causes it to overflow beyond the range of a 32-bit signed integer, the function returns `0`. The function handles both positive and negative numbers, ensuring the sign remains correct after the reversal.

## Step-by-Step Explanation:

1. **Initialization**:
   We begin by checking whether the input number `x` is negative. If `x` is negative, we will need to adjust how we handle the reversal to account for the negative sign.
   
   ```cpp
   bool issigned = (x < 0);
   int res{};
   ```

   - `issigned` is set to `true` if `x` is negative, and `false` if it's positive.
   - `res` is initialized to `0`. This variable will store the reversed number as we process the digits.

2. **Loop Through Digits of `x`**:
   The core of the function is a `while` loop that continues until `x` becomes `0`. In each iteration, we extract the last digit of `x`, append it to `res`, and then remove the last digit from `x`.

   ```cpp
   while (x) {
       int digit = x % 10;
   ```

   - `digit = x % 10` extracts the last digit of `x` (e.g., for `x = 123`, `digit = 3`).
   - The loop runs as long as there are remaining digits in `x`.

3. **Overflow Check**:
   Before modifying `res`, we need to ensure that appending `digit` to `res` does not cause an overflow. Overflow occurs when `res` becomes too large to fit within the bounds of a 32-bit signed integer (`INT_MIN` to `INT_MAX`).

   The overflow check is different for positive and negative numbers because the range of negative numbers is one unit larger than the range of positive numbers. Here, we check if `res` will exceed the limits of a 32-bit signed integer when multiplied by 10 and adding the current digit.

   ```cpp
   if ((!issigned && res > ((std::numeric_limits<int>::max() - digit) / 10)) ||
       (issigned && res < ((std::numeric_limits<int>::lowest() - digit) / 10))) {
       return 0;  // Return 0 if overflow would occur
   }
   ```

   - **For positive numbers** (`!issigned`): We check if multiplying `res` by 10 and adding `digit` would cause `res` to exceed `INT_MAX` (`std::numeric_limits<int>::max()`).
     - This is done by ensuring that `res` is smaller than `(INT_MAX - digit) / 10`. If `res` exceeds this value, multiplying by 10 and adding `digit` would overflow.
   
   - **For negative numbers** (`issigned`): We similarly check for underflow, ensuring that `res` doesn't go below `INT_MIN` (`std::numeric_limits<int>::lowest()`).
     - This check ensures that multiplying `res` by 10 and adding `digit` does not go past the lower bound of the integer range.

   If either condition indicates that an overflow or underflow would occur, the function returns `0`.

4. **Reverse the Number**:
   If the overflow check passes, we safely append the current digit to `res` by multiplying `res` by 10 (shifting the digits left) and adding `digit` to it.

   ```cpp
   res = res * 10 + digit;
   ```

   - This effectively builds the reversed number digit by digit. For example, if `res = 12` and `digit = 3`, the new value of `res` will be `123`.

5. **Remove the Last Digit from `x`**:
   After processing the last digit, we remove it from `x` by dividing `x` by 10.

   ```cpp
   x /= 10;
   ```

   This operation effectively shifts all digits of `x` to the right. For example, if `x = 123`, after `x /= 10`, `x` becomes `12`.

6. **Return the Reversed Number**:
   Once the loop has processed all the digits, we return the reversed number stored in `res`.

   ```cpp
   return res;
   ```

## Key Insights:

- **Overflow Handling**:
  The function checks for overflow or underflow conditions before performing the reversal. This ensures that the reversed number does not exceed the limits of a 32-bit signed integer. Without this check, the function could return incorrect values when an overflow occurs.

- **Sign Preservation**:
  The function handles both positive and negative numbers correctly. If `x` is negative, the sign is preserved in the reversed number by ensuring the overflow checks account for the negative range.

- **Mathematical Properties of Reversal**:
  The reversal of the number is achieved by repeatedly extracting the last digit of `x` and building the reversed number by shifting `res` left (multiplying by 10) and adding the extracted digit.

- **Constant Space**:
  The solution uses **O(1)** space because it only uses a fixed amount of extra memory: `res` for the reversed number and `issigned` for checking the sign. The function doesn't need any additional data structures like arrays or lists.


- **Edge Case Handling**:
  The function correctly handles edge cases like `0`, where `x = 0` immediately exits the loop and returns `0`. It also handles negative numbers correctly by preserving the sign.

---

## Final Thoughts:

This `reverse` solution efficiently reverses the digits of a 32-bit signed integer, checking for overflows and handling both positive and negative numbers. By leveraging simple arithmetic operations and ensuring that overflow conditions are checked before they occur, this solution works reliably and efficiently.
