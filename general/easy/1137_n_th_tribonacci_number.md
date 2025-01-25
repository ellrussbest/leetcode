# Tribonacci Solution: Intuition

This solution calculates the `n`-th number in the Tribonacci sequence, where each number is the sum of the previous three numbers. The sequence is defined as:
- `T(0) = 0`
- `T(1) = 1`
- `T(2) = 1`
- For `n >= 3`, `T(n) = T(n-1) + T(n-2) + T(n-3)`

## Step-by-Step Explanation:

1. **Base Case Handling**:
   - If `n == 0`, we immediately return `0` since `T(0) = 0`.

   ```cpp
   if (n == 0)
       return 0;
   ```

2. **Initialization**:
   - A vector `dp` is created to store the Tribonacci values for all numbers up to `n`. We initialize `dp[1] = 1` because `T(1) = 1`.

   ```cpp
   auto N = static_cast<size_t>(n);
   std::vector<int> dp(N + 1, 0);
   dp[1] = 1;
   ```

3. **Dynamic Programming Iteration**:
   - We loop through the `dp` array and, for each index `i`, we loop from `1` to `3` (representing the next three steps). For each of these steps `j`, we check if `i + j` is within the bounds of the array and, if so, update `dp[i + j]` by adding `dp[i]`. This ensures that the current value contributes to the next three values in the sequence.

   ```cpp
   for (size_t i = 0; i < dp.size(); ++i) {
       for (size_t j = 1; j <= 3; ++j) {
           if (i + j < dp.size())
               dp[i + j] += dp[i];
       }
   }
   ```

4. **Return Result**:
   - After the loops are finished, the value `dp[N]` will contain the Tribonacci number for `n`.

   ```cpp
   return dp[N];
   ```

5. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because we loop through the array once and perform a constant amount of work (the inner loop runs 3 times for each iteration of the outer loop).
   - **Space Complexity**: The space complexity is **O(n)** because we use a vector of size `n + 1` to store the Tribonacci values.

## Key Insights:

- **Dynamic Programming with Nested Loops**:
  - This solution uses dynamic programming to efficiently compute the Tribonacci sequence. The nested loops enable updating the next three values at each step, which follows the recurrence relation of the Tribonacci sequence.

- **Efficiently Handling Multiple Steps**:
  - Instead of manually updating each subsequent index (`i + 1`, `i + 2`, `i + 3`), the inner loop generalizes the process. This allows for flexibility and makes the code more concise by looping through `j = 1, 2, 3`.

- **Space Complexity Consideration**:
  - The current implementation stores all intermediate values in the `dp` vector. However, the space complexity could be optimized further by maintaining only the last three values, reducing it to **O(1)**.

## Final Thoughts:

This `tribonacci` solution calculates the Tribonacci number in **O(n)** time and **O(n)** space using dynamic programming. The solution is efficient and easy to understand, but with some further space optimization (keeping track of only the last three values), the space complexity could be reduced to constant space.

---
