# House Robber Problem: Solution and Intuition

The goal of this solution is to determine the maximum amount of money that can be robbed from a list of houses, where each house has a certain amount of money. The key constraint is that two adjacent houses cannot be robbed on the same night.

## Problem Breakdown:

1. **Input**: A list of integers `nums`, where each element represents the amount of money in a house.
2. **Output**: The maximum amount of money that can be robbed, following the constraint that no two adjacent houses can be robbed in the same night.

## Step-by-Step Explanation:

### 1. **Initialization**:
   - The solution uses a helper function `rob_helper`, which will handle the recursion and memoization to avoid recalculating the same subproblems multiple times.
   - An unordered map `memo` is used to store the results of previously computed subproblems, allowing the algorithm to skip redundant calculations.

   ```cpp
   std::unordered_map<size_t, int> memo;
   return rob_helper(nums, nums.size(), memo);
   ```

### 2. **Recursive Helper Function**:
   - The helper function `rob_helper` uses two base cases:
     - If the index is `0`, the return value is `0` (no house to rob).
     - If the index is `1`, return the value at `nums[0]` (the only house).
   
   - If the result for the current index `idx` has already been computed (i.e., it's in `memo`), the function returns that result.

   ```cpp
   if(auto it = memo.find(idx); it != memo.end())
       return it->second;
   ```

   - Otherwise, we calculate two possible outcomes:
     - **Skip the current house**: Take the result of `rob_helper` for the previous house (`idx - 1`).
     - **Rob the current house**: Add the value of the current house (`nums[idx - 1]`) to the result of robbing the house two steps before (`idx - 2`).
   
   - We then store the maximum of the two outcomes in `memo` to avoid recalculating it in the future.

   ```cpp
   int skip_current = rob_helper(nums, idx - 1, memo);
   int rob_current = nums[idx - 1] + rob_helper(nums, idx - 2, memo);
   memo.try_emplace(idx, std::max(rob_current, skip_current));
   ```

   - Finally, the function returns the maximum of the two options.

   ```cpp
   return std::max(rob_current, skip_current);
   ```

### 3. **Return the Result**:
   - The main function calls `rob_helper` with the size of the input list to calculate the final result.
   - Example outputs are shown in the `main()` function.

   ```cpp
   std::cout << Solution{}.rob({1, 2, 3, 1}) << "\n";  // Outputs: 4
   std::cout << Solution{}.rob({2, 7, 9, 3, 1}) << "\n";  // Outputs: 12
   ```

### 4. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the number of houses. This is because we calculate the maximum money for each house at most once, thanks to memoization.
   - **Space Complexity**: The space complexity is **O(n)** due to the space required for the `memo` map, which stores the result for each house.

## Key Insights:

- **Memoization**:
  - The solution leverages memoization to store intermediate results and avoid redundant recursive calls, making the algorithm efficient.
  
- **Recursion with Dynamic Programming**:
  - This approach is a combination of recursion and dynamic programming, ensuring that we solve subproblems only once and build up to the final solution.

## Final Thoughts:

This solution efficiently calculates the maximum amount of money that can be robbed using **O(n)** time and space. By combining recursion and memoization, it avoids recalculating overlapping subproblems, making it optimal for this problem.
