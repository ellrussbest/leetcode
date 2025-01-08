# `firstMissingPositive` Solution: Intuition

This solution finds the smallest missing positive integer from an unsorted array of integers. It modifies the input array in-place and uses indexing to efficiently track the presence of numbers. The approach avoids extra space and runs in linear time.

## Step-by-Step Explanation:

1. **Initialization**:
   - The variable `res` is initialized to the size of the array `nums` plus 1, as the smallest missing positive integer must lie between `1` and `n + 1`, where `n` is the size of the array.
   - We iterate through the array, replacing any non-positive numbers (≤ 0) with `res` (effectively marking them as invalid for our future checks).
   
   ```cpp
   int res = static_cast<int>(nums.size()) + 1;

   for (auto& num : nums) {
       if (num <= 0)
           num = res;
   }
   ```

2. **Marking Presence of Numbers**:
   - The idea is to mark the presence of numbers within the range `[1, n]` by using negative indexing.
   - We loop through the array and for each positive number `nums[i]`, calculate its corresponding index `idx = |nums[i]| - 1`. If the number at that index is positive, we mark it as negative to indicate that the number `nums[i]` is present.
   - This marks the number's presence without using any extra space, leveraging the array itself for indexing.

   ```cpp
   for (size_t i = 0; i < nums.size(); ++i) {
        int idx = std::abs(nums[i]) - 1;
        size_t N = static_cast<size_t>(idx);

        if (N < nums.size() && nums[N] > 0)
            nums[N] *= -1;
   }
   ```

3. **Finding the Missing Positive Integer**:
   - After marking, the first index with a positive number represents the smallest missing positive integer (i.e., the number corresponding to that index is absent from the array).
   - We return `i + 1` where `i` is the first such index.

   ```cpp
   for (size_t i = 0; i < nums.size(); ++i) {
       if (nums[i] > 0)
           return static_cast<int>(i) + 1;
   }
   ```

4. **Return the Result**:
   - If no missing number is found within the range `[1, n]`, we return `res`, which was initialized to `n + 1`, as the answer.

   ```cpp
   return res;
   ```

5. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because we loop through the array a constant number of times (3 passes).
   - **Space Complexity**: The space complexity is **O(1)** because the solution works in-place, using no extra data structures except for a few integer variables.

## Key Insights:

- **In-Place Modification**:
  - The solution modifies the input array in-place, allowing it to track the presence of numbers without requiring additional space.
  
- **Efficient Use of Indices**:
  - The solution utilizes array indices to mark presence by flipping the sign of elements. This avoids the need for additional sets or hashmaps.

- **Handling Edge Cases**:
  - Non-positive numbers and numbers greater than `n` are effectively ignored by setting them to a value that cannot impact the final result.

## Final Thoughts:

The `firstMissingPositive` solution efficiently finds the smallest missing positive integer in **O(n)** time and **O(1)** space. By modifying the input array and using the indices to track the presence of numbers, this solution provides an optimal approach to the problem with no need for extra memory allocation.