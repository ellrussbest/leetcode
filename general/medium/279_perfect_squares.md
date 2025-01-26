# numSquares Solution: Intuition

This solution solves the problem of finding the minimum number of perfect squares that sum to a given number `n`. It uses dynamic programming to build up the solution in an efficient manner.

## Step-by-Step Explanation:

1. **Initialization**:
   - We create a vector `dp` of size `n+1` to store the minimum number of perfect squares for each number from `0` to `n`. Initially, all values are set to `-1` (representing uncomputed values), except for `dp[0]`, which is set to `0` (base case: zero requires zero perfect squares).

   ```cpp
   size_t N = static_cast<size_t>(n);
   std::vector<int> dp(N + 1, -1);
   dp[0] = 0;
   ```

2. **Iterate and Update Dynamic Programming Table**:
   - We iterate over each value in `dp`, starting from `0`.
   - For each `i`, we try adding square numbers `1^2, 2^2, 3^2,...` and check if we can reduce the number of perfect squares needed to reach `i + square`. If a smaller number of perfect squares can be achieved, we update `dp[i + square]`.

   ```cpp
   for (size_t i = 0; i < dp.size(); ++i) {
       size_t j = 1;
       auto sq = j * j;

       if (dp[i] != -1) {
           while (sq <= N) {
               if (i + sq < dp.size()) {
                   if (dp[i + sq] == -1)
                       dp[i + sq] = dp[i] + 1;
                   else
                       dp[i + sq] = std::min(dp[i + sq], dp[i] + 1);
               }
               ++j;
               sq = j * j;
           }
       }
   }
   ```

3. **Return Result**:
   - After iterating through the `dp` table, the final result is stored in `dp[N]`, which represents the minimum number of perfect squares that sum to `n`.

   ```cpp
   return dp[N];
   ```

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n * sqrt(n))** because for each number from `0` to `n`, we try adding perfect squares, and the number of perfect squares up to `n` is approximately `sqrt(n)`.
   - **Space Complexity**: The space complexity is **O(n)** due to the vector `dp` of size `n + 1`.

## Key Insights:

- **Dynamic Programming**:
  - The solution uses dynamic programming to build up the solution progressively. This avoids redundant calculations and ensures that the result is computed in an efficient manner.

- **Efficient State Transitions**:
  - Instead of recalculating the number of perfect squares for each value of `i`, we reuse previously computed values and only update the ones that can be reduced by adding a square.

- **Optimization**:
  - The inner loop checks squares incrementally (`1^2, 2^2, 3^2,...`) and updates the `dp` table only when a better (smaller) number of squares is found, ensuring an optimized approach.

## Final Thoughts:

This solution computes the minimum number of perfect squares for a given number `n` efficiently with a time complexity of **O(n * sqrt(n))**. By leveraging dynamic programming, it avoids redundant calculations and provides a simple yet effective approach to solving the problem.
