# Coin Change Solution: Intuition

This solution calculates the minimum number of coins required to make a given amount using the provided denominations. The approach leverages dynamic programming (DP) to efficiently solve the problem.

## Step-by-Step Explanation:

1. **Initialization**:
   - We create a vector `dp` of size `amount + 1`, initialized to `-1` to indicate that the amount cannot be made with the given coins initially.
   - The base case is `dp[0] = 0`, since no coins are needed to make the amount 0.

   ```cpp
   std::vector<int> dp(static_cast<size_t>(amount + 1), -1);
   dp[0] = 0;
   ```

2. **Filling the DP Table**:
   - We iterate through the `dp` vector from `0` to `amount`.
   - For each index `i` where `dp[i] != -1`, we consider all coins available. If the coin can be used to make a new amount `i + coin`, we update `dp[i + coin]` to reflect the minimum number of coins required.
   - If `dp[i + coin]` is not already set (`-1`), we set it to `dp[i] + 1`, which means using one more coin from the current state `i`. If it’s already set, we update it to the minimum of the existing value and `dp[i] + 1`.

   ```cpp
   for (size_t i = 0; i < dp.size(); ++i) {
       if (dp[i] != -1) {
           for (const auto& coin : coins) {
               auto idx = i + static_cast<size_t>(coin);
               if (idx < dp.size()) {
                   if (dp[idx] == -1)
                       dp[idx] = dp[i] + 1;
                   else
                       dp[idx] = std::min(dp[idx], dp[i] + 1);
               }
           }
       }
   }
   ```

3. **Return Result**:
   - The value in `dp[amount]` gives the minimum number of coins required to make the target amount. If `dp[amount]` is still `-1`, it means the amount cannot be made with the given coins.

   ```cpp
   return dp[static_cast<size_t>(amount)];
   ```

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(amount * n)** where `n` is the number of coins, as for each possible amount up to `amount`, we check each coin.
   - **Space Complexity**: The space complexity is **O(amount)** due to the `dp` vector storing the minimum number of coins for all amounts from 0 to `amount`.

## Key Insights:

- **Dynamic Programming**:
  - This solution uses a bottom-up dynamic programming approach, filling the `dp` array iteratively to find the minimum number of coins.
  
- **Efficiency**:
  - By checking each amount in the `dp` array only once and updating the corresponding entries based on the available coins, the solution avoids recomputation and optimizes the process.

- **Handling Edge Cases**:
  - The solution handles edge cases, like when `amount` is `0` (returns 0 coins), or when no combination of coins can make the target amount (returns -1).

## Final Thoughts:

This coin change solution solves the problem efficiently using dynamic programming, with a time complexity of **O(amount * n)** and a space complexity of **O(amount)**. It ensures that the minimum number of coins is computed for any given target amount and coin denominations.
