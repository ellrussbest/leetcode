# canReach Solution: Intuition

This solution determines whether it's possible to reach an index with the value `0` starting from a given index in the array. The rules for movement are:
- From a given index, you can move either left or right by the number of steps equal to the value at the current index.
- The value at the current index is negated once visited to prevent revisiting the same index.

## Step-by-Step Explanation:

1. **Initialization**:
   - The function `canReach` is called with the array `arr` and a starting index `start`.
   - The helper function `can_reach_helper` is then invoked to determine whether it's possible to reach an index with a value of `0`.

   ```cpp
   return can_reach_helper(arr, start);
   ```

2. **Base Case Check**:
   - In the helper function, the base case checks are:
     - Whether the current index is out of bounds (`start < 0 || start >= arr.size()`).
     - Whether the current index has already been visited (indicated by a negative value at the index).
     - If the value at the current index is `0`, meaning the target has been reached.

   ```cpp
   if (start < 0 || start >= static_cast<int>(arr.size()) || arr[N] < 0)
       return false;
   if (arr[N] == 0)
       return true;
   ```

3. **Recursive Step**:
   - The value at the current index is negated (`arr[N] *= -1`) to mark the index as visited.
   - The function recursively checks both left and right movements based on the absolute value of the current index's value.
   - The next index to visit is `start - abs(arr[start])` for left movement and `start + abs(arr[start])` for right movement.

   ```cpp
   arr[N] *= -1;
   auto left = can_reach_helper(arr, start - std::abs(arr[N]));
   auto right = can_reach_helper(arr, start + std::abs(arr[N]));
   ```

4. **Return Result**:
   - The function returns `true` if either the left or right recursive calls return `true`, indicating that the target index (`0`) can be reached.

   ```cpp
   return left || right;
   ```

5. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because each index is visited at most once, and each visit involves a constant amount of work (i.e., checking divisibility and performing recursive calls).
   - **Space Complexity**: The space complexity is **O(n)** due to the recursion stack, where the maximum recursion depth corresponds to the number of elements in the array.

## Key Insights:

- **Negating Values to Prevent Revisit**:
  - The key mechanism to avoid revisiting an index is by negating its value once visited. This ensures that we do not enter into an infinite loop.

- **Recursive Approach**:
  - The solution uses recursion to explore both possible directions (left and right) for each index. This makes the solution compact but relies on the call stack to manage state.

- **Efficient Boundary Checks**:
  - The solution handles edge cases early (out-of-bounds indices and revisited indices) to prune unnecessary recursive calls and prevent stack overflow or incorrect results.

## Final Thoughts:

This solution efficiently checks whether a target index can be reached in **O(n)** time and **O(n)** space by using a recursive approach with in-place negation to avoid revisiting indices. It provides a clear and effective solution to the problem of determining reachability in an array with dynamic step sizes.
