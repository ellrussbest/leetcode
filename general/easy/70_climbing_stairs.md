# Climbing Stairs Solution: Intuition

This solution calculates the number of distinct ways to climb a staircase with `n` steps, where you can either take 1 step or 2 steps at a time. The goal is to find how many distinct ways you can reach the top.

## Step-by-Step Explanation:

1. **Initialization**:
   - We create a vector `dp` of size `n + 1` to store the number of ways to reach each step.
   - The vector is initialized to zero, and we set `dp[0] = 1` because there is exactly one way to be at the ground (step 0).

   ```cpp
   auto N = static_cast<size_t>(n);
   std::vector<int> dp(N + 1, 0);
   dp[0] = 1;
   ```

2. **Dynamic Programming Iteration**:
   - We loop through each step (from `0` to `n`) and update the number of ways to reach the subsequent steps:
     - For each `i`, we check if `i + 1` and `i + 2` are within bounds. If they are, we add the current number of ways (`dp[i]`) to `dp[i + 1]` and `dp[i + 2]`. This simulates the choice of taking 1 step or 2 steps.
   
   ```cpp
   for (size_t i = 0; i < dp.size(); ++i) {
       if (i + 1 < dp.size())
           dp[i + 1] += dp[i];
       if (i + 2 < dp.size())
           dp[i + 2] += dp[i];
   }
   ```

3. **Return Result**:
   - After processing all the steps, the final value `dp[N]` will contain the total number of ways to reach the top of the staircase.

   ```cpp
   return dp[N];
   ```

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because we loop through the number of steps once and perform constant-time operations for each step.
   - **Space Complexity**: The space complexity is **O(n)** because we store the number of ways to reach each step in a vector of size `n + 1`.

## Key Insights:

- **Dynamic Programming Approach**:
  - This problem is a classic example where dynamic programming is used to build the solution incrementally. By storing intermediate results (`dp` array), we avoid redundant calculations and solve the problem efficiently.

- **Transitioning Between States**:
  - At each step `i`, we only need to know the number of ways to reach `i`, which is used to calculate the number of ways to reach `i + 1` and `i + 2`. This enables efficient computation.

- **Space Optimization**:
  - We use a full array to store the results for each step. While this solution uses O(n) space, we could optimize this further by only keeping track of the last two results, as the number of ways to reach step `i` only depends on steps `i-1` and `i-2`.

## Final Thoughts:

This `climbStairs` solution calculates the number of ways to climb to the top in **O(n)** time and **O(n)** space. It efficiently handles the problem using dynamic programming and offers a clear, understandable approach to solving this common algorithmic problem. With some space optimization, this could be made even more efficient.
