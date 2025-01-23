# Maximum Subarray Solution: Intuition

This solution finds the **maximum sum of a contiguous subarray** within a given list of integers using **Kadane's Algorithm**. The goal is to find the subarray with the largest sum, and this solution does so efficiently in linear time and constant space.

## Step-by-Step Explanation:

1. **Initialization**:
   - We initialize two variables:
     - `cur_sum`: This tracks the current sum of the subarray being considered. It is initialized to the smallest possible integer value (`std::numeric_limits<int>::lowest()`), ensuring that any value from the list will be larger.
     - `max_sum`: This tracks the maximum sum encountered so far. It is also initialized to the smallest possible integer value.

   ```cpp
   int cur_sum = std::numeric_limits<int>::lowest();
   int max_sum = std::numeric_limits<int>::lowest();
   ```

2. **Iterate Through the List**:
   - We loop through the list and update `cur_sum` and `max_sum`:
     - If `cur_sum` is negative, it means starting fresh from the current element is better, so we set `cur_sum` to the current element.
     - Otherwise, we add the current element to `cur_sum`.
     - After updating `cur_sum`, we update `max_sum` to ensure it always holds the largest sum encountered.

   ```cpp
   for (const auto& num : nums) {
       if (cur_sum < 0)
           cur_sum = num;
       else
           cur_sum += num;

       max_sum = std::max(max_sum, cur_sum);
   }
   ```

3. **Return the Maximum Sum**:
   - After the loop finishes, `max_sum` holds the largest sum of any contiguous subarray. We return `max_sum`.

   ```cpp
   return max_sum;
   ```

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, as we only iterate through the list once.
   - **Space Complexity**: The space complexity is **O(1)** because we only use a constant amount of extra space for `cur_sum` and `max_sum`.

## Key Insights:

- **Kadane's Algorithm**:
  - Kadane's algorithm efficiently solves the maximum subarray problem by dynamically deciding whether to continue the current subarray or start a new one. This decision is based on whether the current sum (`cur_sum`) is negative. If it is, starting fresh from the current element will likely result in a higher sum.
  
- **Efficiency**:
  - The algorithm runs in **O(n)** time and requires **O(1)** space, making it optimal for large inputs where both time and space efficiency are important.

- **Edge Case Handling**:
  - This solution correctly handles edge cases like arrays with a single element or arrays with all negative numbers. The use of `std::numeric_limits<int>::lowest()` ensures that even in extreme cases, the solution behaves correctly.

## Final Thoughts:

This solution efficiently solves the maximum subarray sum problem with **Kadane's Algorithm**. By maintaining a running sum and updating the maximum sum dynamically, it ensures optimal time complexity of **O(n)** and space complexity of **O(1)**. It is ideal for large datasets and handles various edge cases effectively.
