# Find Disappeared Numbers Solution: Intuition

This solution identifies the missing numbers in an array of integers ranging from `1` to `n`. The algorithm modifies the input array in place to track which numbers are present and uses this modification to efficiently identify missing numbers without requiring additional space.

## Step-by-Step Explanation:

### 1. **Initialization**:
   - **Result Vector**: We initialize an empty vector `res` to store the missing numbers that will be found in the array.
   - **In-place Modification**: The input array `nums` is modified in place. The key observation is that the value at each index represents a number, and by marking the corresponding index (derived from that number) as negative, we can track which numbers have been seen.

   ```cpp
   std::vector<int> res;
   ```

### 2. **Marking Present Numbers**:
   We loop through each element of `nums` and for each element `nums[i]`:
   - Compute the index corresponding to the value `nums[i]` by calculating `idx = abs(nums[i]) - 1`. This is the index where the number `nums[i]` should appear in a properly ordered array of `1` to `n`.
   - If the number at `nums[idx]` is positive, it indicates that the number corresponding to that index hasn’t been encountered yet, so we mark it as negative. This marks the presence of that number.
   
   **Key Insight**: By making the value at the index `idx` negative, we "mark" that the number `idx + 1` has been seen in the array. This allows us to use the array itself to track which numbers are present.

   ```cpp
   for(size_t i = 0; i < nums.size(); ++i) {
       int idx = std::abs(nums[i]) - 1;  // Calculate index for the number
       size_t N = static_cast<size_t>(idx);

       // If the number at index N is positive, mark it as seen by making it negative
       if(nums[N] > 0)
           nums[N] *= -1;
   }
   ```

### 3. **Identifying Missing Numbers**:
   After marking the present numbers, we loop through the array again:
   - If the value at any index `i` is positive, it means that the number `i + 1` is missing (since the corresponding number was never marked as negative).
   - We add the missing number `i + 1` to the result vector `res`.

   ```cpp
   for(size_t i = 0; i < nums.size(); ++i) {
       if(nums[i] > 0)  // If the number at index i is positive, it's missing
           res.emplace_back(static_cast<int>(i + 1));  // Add to result
   }
   ```

### 4. **Return Result**:
   Finally, after both loops, we return the vector `res` containing all the missing numbers.

   ```cpp
   return res;
   ```

### 5. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the number of elements in the input array. This is because we make two passes over the array: one for marking present numbers and another for collecting the missing ones. Both operations take linear time.
   - **Space Complexity**: The space complexity is **O(1)**, because the algorithm modifies the input array in place and does not use any additional data structures except for the output vector `res`.

## Key Insights:

- **In-Place Modification**: 
  - The algorithm uses the array itself to mark the presence of numbers, avoiding the need for additional space. This allows the solution to operate in constant space, making it space-efficient.
  
- **Mathematical Insight**:
  - The use of the absolute value of `nums[i]` and subtracting `1` to calculate the index provides a way to map each number to an index and mark it as "seen" by flipping the sign of the corresponding element.

- **Efficient Use of Input Array**:
  - This technique leverages the input array itself for state tracking, which eliminates the need for extra space, making the solution both time-efficient and space-efficient.

## Final Thoughts:

This solution efficiently identifies missing numbers from an array of integers between `1` and `n` in **O(n)** time and **O(1)** space. By marking indices in the input array itself, the algorithm minimizes space usage while ensuring correctness. This approach is a perfect example of utilizing in-place modifications to optimize space complexity without sacrificing performance.
