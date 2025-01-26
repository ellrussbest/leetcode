# minCostClimbingStairs Solution: Intuition

This solution calculates the minimum cost to reach the top of a staircase, where you can climb either one or two steps at a time. The cost to step on each stair is provided, and the goal is to minimize the total cost to reach the top.

## Step-by-Step Explanation:

1. **Initialization**:
   - We create a dynamic programming vector `dp` of size `n+1` to store the minimum cost to reach each step, where `n` is the number of stairs. We initialize the first two steps (`dp[0]` and `dp[1]`) to `0` because there is no cost to start on the ground or the first step.
   
   ```cpp
   size_t N = cost.size();
   std::vector<int> dp(N + 1, -1);
   dp[0] = 0;
   dp[1] = 0;
   ```

2. **Iterate and Update Dynamic Programming Table**:
   - We loop through the stairs from `0` to `n-1`. For each step `i`, we consider two possible moves:
     - **Move 1 step up**: Update `dp[i + 1]` with the minimum cost to reach it from `i`.
     - **Move 2 steps up**: Update `dp[i + 2]` with the minimum cost to reach it from `i`.
     
   - For both moves, we calculate the cost by adding the cost at the current step `cost[i]` and compare it to the existing value in `dp` to ensure we're using the minimum cost.

   ```cpp
   for (size_t i = 0; i < N; ++i) {
       if (i + 1 < dp.size()) {
           if (dp[i + 1] == -1)
               dp[i + 1] = dp[i] + cost[i];
           else
               dp[i + 1] = std::min(dp[i + 1], dp[i] + cost[i]);
       }

       if (i + 2 < dp.size()) {
           if (dp[i + 2] == -1)
               dp[i + 2] = dp[i] + cost[i];
           else
               dp[i + 2] = std::min(dp[i + 2], dp[i] + cost[i]);
       }
   }
   ```

3. **Return Result**:
   - After processing all stairs, the minimum cost to reach the top is stored in `dp[N]`, where `N` is the total number of steps. We return this value as the result.

   ```cpp
   return dp[N];
   ```

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because we loop through all the stairs once and perform constant-time operations for each step.
   - **Space Complexity**: The space complexity is **O(n)** due to the dynamic programming vector `dp` which stores the minimum cost for each step.

## Key Insights:

- **Dynamic Programming**:
  - The solution uses dynamic programming to build up the minimum cost progressively. This avoids recalculating the minimum cost for each step multiple times, improving efficiency.
  
- **Efficient State Transitions**:
  - At each step, we consider two possible moves: one step or two steps, and update the cost accordingly. This ensures that we always keep track of the minimum cost to reach the next step.

- **Handling Boundaries**:
  - We carefully check the bounds (`i + 1` and `i + 2`) before attempting to access `dp`, ensuring that we don't go out of range.

## Final Thoughts:

This solution computes the minimum cost to reach the top of the staircase with a time complexity of **O(n)** and a space complexity of **O(n)**. By using dynamic programming, we efficiently calculate the optimal cost, ensuring an optimal approach for solving the problem.
