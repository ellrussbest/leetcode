# Trailing Zeroes in Factorials: Intuition

This solution calculates the number of trailing zeroes in the factorial of a given number `n`. Two methods are provided: a **more efficient approach** that counts factors of 5, and a **brute-force approach** that calculates the factorial and counts the trailing zeroes directly.

## Step-by-Step Explanation:

### 1. **Efficient Approach (`trailingZeroes`)**:
   The first method leverages the fact that trailing zeroes in a number are produced by factors of 10, and 10 is the product of 2 and 5. In a factorial, the number of 2s will always outnumber the number of 5s, so we focus on counting the number of factors of 5.

   ```cpp
   int fives{};
   for (int i = 5; i <= n; i = i * 5) fives += (n / i);
   return fives;
   ```

   - **Iterate through powers of 5**:  
     The loop starts from 5 and continues by multiplying `i` by 5 at each step. For each power of 5, we calculate how many times it divides `n`. This gives us the number of factors of 5 in the factorial of `n`.
     - `n / i`: This expression gives the number of multiples of `i` (5, 25, 125, etc.) that are less than or equal to `n`.
   
   - **Count factors of 5**:  
     For each iteration, we add the result of `n / i` to the `fives` variable. This variable keeps track of the total number of factors of 5, which corresponds to the number of trailing zeroes in `n!`.

   - **Why only powers of 5?**  
     Since each factor of 5 combines with a factor of 2 to create a trailing zero, counting multiples of 5 gives the correct number of trailing zeroes without needing to explicitly calculate the factorial.

### 2. **Brute Force Approach (`trailingZeroes_bruteforce`)**:
   The second method directly calculates the factorial of `n` and then counts the number of trailing zeroes by repeatedly dividing the result by 10.

   ```cpp
   unsigned long fact = 1;
   for (auto i = 2; i <= n; ++i) fact *= static_cast<unsigned long>(i);
   
   int count = 0;
   while (fact % 10 == 0) {
       ++count;
       fact /= 10;
   }
   
   return count;
   ```

   - **Calculate the factorial**:  
     The first loop computes the factorial of `n` by multiplying each integer from 2 to `n` and storing the result in the `fact` variable.
   
   - **Count trailing zeroes**:  
     After calculating the factorial, the second loop checks how many times `fact` is divisible by 10. Each division by 10 removes one trailing zero, and the loop increments `count` for each trailing zero found.
     - `fact % 10 == 0`: Checks if the last digit of `fact` is 0, indicating a trailing zero.
     - `fact /= 10`: Divides `fact` by 10 to remove the last digit and checks again.

### 3. **Edge Case Handling**:
   - **Factorial of 0**:  
     The factorial of 0 is defined as 1 (`0! = 1`), which has 0 trailing zeroes. Both methods correctly handle this case by returning 0 when `n` is 0.
   
   - **Small values of `n`**:  
     For small values of `n`, such as 1, 2, or 3, the factorials do not contain trailing zeroes, so the methods correctly return 0 in these cases.

## Key Insights:

- **Efficient Approach**:  
  The efficient method (`trailingZeroes`) avoids directly calculating the factorial, which can become computationally expensive for large values of `n`. Instead, it counts the number of factors of 5, which is a far more efficient way of determining the number of trailing zeroes.

- **Brute Force Method**:  
  The brute-force approach (`trailingZeroes_bruteforce`) directly calculates the factorial and counts trailing zeroes by checking divisibility by 10. This method is less efficient due to the large size of the factorial as `n` increases.

- **Time Complexity**:
  - The **efficient approach** has a time complexity of **O(log n)** because it iterates over the powers of 5 up to `n`.
  - The **brute force approach** has a time complexity of **O(n)** for calculating the factorial, plus additional checks for trailing zeroes.

- **Space Complexity**:
  Both methods use **O(1)** space, as they only require a few variables to store the result and intermediate calculations, without any additional data structures.

## Final Thoughts:

This solution provides two methods for calculating the number of trailing zeroes in the factorial of a number `n`. The first method is efficient, focusing on counting factors of 5, while the second method calculates the factorial and checks for trailing zeroes directly. The efficient approach is preferable for large values of `n` due to its logarithmic time complexity, while the brute-force method offers a more straightforward (though less efficient) solution.