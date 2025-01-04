# Jump Game Solution: Intuition

This solution determines whether it's possible to reach the last index of an array given an array of numbers. Each number represents the maximum jump length from that index.

## Step-by-Step Explanation:

1. **Initialization**:
   - We start by checking if the input array has only one element. If it does, return `true` as we are already at the last index.
   - The variable `bound` keeps track of the farthest index that can be reached at any given point.

   ```cpp
   if(nums.size() == 1) return true;
   auto bound = *nums.begin();
   ```

2. **Iterate Through the Array**:
   - We loop through the array starting from index `1` (since index `0` is the start point). For each index `i`, we:
     - Check if the current index `i` is beyond the `bound`. If so, return `false` because we can't reach this index.
     - Otherwise, update the `bound` to the maximum of its current value or `i + nums[i]`, which represents the farthest index reachable from index `i`.

   ```cpp
   for(int i = 1; i < static_cast<int>(nums.size()); ++i) {
       if(i > bound)
           return false;
       bound = std::max(bound, i + *std::next(nums.begin(), i));
   }
   ```

3. **Return Result**:
   - If we finish iterating through the array without returning `false`, it means we can reach the last index, so we return `true`.

   ```cpp
   return true;
   ```

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because we loop through the array once, performing constant-time operations for each index.
   - **Space Complexity**: The space complexity is **O(1)** because we only use a few extra variables (`bound`), regardless of the size of the input.

## Key Insights:

- **Farthest Reachable Index**:
  - The solution works by tracking the farthest index we can reach as we iterate through the array. If at any point we encounter an index beyond this reach, we return `false`.

- **Efficient Iteration**:
  - The algorithm only requires one pass through the array, making it efficient with a linear time complexity.

- **No Extra Space**:
  - By only using a few extra variables, the solution is space-efficient with a constant space complexity of **O(1)**.

## Final Thoughts:

This `canJump` solution solves the problem efficiently in **O(n)** time with **O(1)** space. By tracking the farthest reachable index and updating it during the iteration, we ensure that we only need a single loop through the array to determine if it's possible to reach the last index.
